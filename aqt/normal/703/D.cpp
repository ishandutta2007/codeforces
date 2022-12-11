#include <bits/stdc++.h>

using namespace std;

int N, Q;
int BIT[2][1000005];
int lft[1000005], rht[1000005];
pair<int, int> qu[1000005];
int arr[1000005];
int ans[1000005];
map<int, int> lst;

void upd(int t, int n ,int v){
    for(int i = n; i<=N; i+=i&-i){
        BIT[t][i] ^= v;
    }
}

int query(int t, int n){
    int ret = 0;
    for(int i = n; i; i-=i&-i){
        ret ^= BIT[t][i];
    }
    return ret;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
        upd(0, i, arr[i]);
    }
    cin >> Q;
    for(int q = 1; q<=Q; q++){
        cin >> lft[q] >> rht[q];
        qu[q].first = rht[q];
        qu[q].second = q;
    }
    sort(qu+1, qu+1+Q);
    int idx = 0;
    for(int q = 1; q<=Q; q++){
        while(idx < qu[q].first){
            idx++;
            if(lst.count(arr[idx])){
                upd(1, lst[arr[idx]], arr[idx]);
            }
            upd(1, idx, arr[idx]);
            lst[arr[idx]] = idx;
        }
        int i = qu[q].second;
        ans[i] = (query(0, rht[i]) ^ query(0, lft[i]-1) ^ query(1, rht[i]) ^ query(1, lft[i]-1));
    }
    for(int q = 1; q<=Q; q++){
        cout << ans[q] << "\n";
    }
}