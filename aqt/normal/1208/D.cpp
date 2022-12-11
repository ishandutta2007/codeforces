#include <bits/stdc++.h>

using namespace std;

int N;
long long BIT[200005];
long long arr[200005];
int ans[200005];

void upd(int p, int v){
    for(int i = p; i<=N; i+=i&-i){
        BIT[i]+=v;
    }
}

long long query(int p){
    long long s = 0;
    for(int i = p; i>0; i-=i&-i){
        s += BIT[i];
    }
    return s;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
        upd(i, i);
    }
    for(int i = N; i>0; i--){
        int l = 1, r = N;
        while(l <= r){
            int mid = l+r>>1;
            if(query(mid-1) <= arr[i]){
                l = mid + 1;
                ans[i] = mid;
            }
            else{
                r = mid - 1;
            }
        }
        upd(ans[i], -ans[i]);
    }
    for(int i= 1; i<=N; i++){
        cout << ans[i] << " ";
    }
}