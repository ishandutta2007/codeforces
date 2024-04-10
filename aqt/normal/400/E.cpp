#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[100005];
long long tot = 0;
set<int> st[20];

long long calc(long long l, long long r){
    return (r-l-1)*(r-l)/2;
}

void upd(int p, int t){
    for(int k = 0; k<17; k++){
        if((1<<k)&arr[p]){
            if(t == 1){
                st[k].erase(p);
            }
            else{
                st[k].insert(p);
            }
            int r = *st[k].upper_bound(p), l = *(--st[k].lower_bound(p));
            tot += (1LL<<k)*t*calc(l, r);
            tot -= (1LL<<k)*t*calc(l, p);
            tot -= (1LL<<k)*t*calc(p, r);
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for(int k = 0; k<17; k++){
        st[k].insert(0), st[k].insert(N+1);
    }
    for(int i= 1; i<=N ; i++){
        cin >> arr[i];
        for(int k = 0; k<17; k++){
            st[k].insert(i);
        }
    }
    for(int i= 1; i<=N; i++){
        upd(i, 1);
    }
    while(M--){
        int p, v;
        cin >> p >> v;
        upd(p, -1);
        arr[p] = v;
        upd(p, 1);
        cout << tot << "\n";
    }
}