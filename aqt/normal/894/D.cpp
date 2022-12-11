#include <bits/stdc++.h>

using namespace std;

int N, Q;
int len[1000005];
vector<int> pth[2000005];
vector<long long> pre[1000005];

long long solve(int n, int lim){
    int l = 1, r = pth[n].size(), ans = 0;
    while(l <= r){
        int mid = l+r>>1;
        if(pth[n][mid-1] <= lim){
            ans = mid;
            l = mid+1;
        }
        else{
            r= mid-1;
        }
    }
    if(!ans){
        return 0;
    }
    return 1LL*ans*lim - pre[n][ans-1];
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> Q;
    for(int i = 2; i<=N; i++){
        cin >> len[i];
    }
    for(int n = N; n; n--){
        pth[n].push_back(0);
        for(int k : pth[n]){
            pth[n>>1].push_back(k+len[n]);
        }
        sort(pth[n].begin(), pth[n].end());
        long long s = 0;
        for(int k : pth[n]){
            s += k;
            pre[n].push_back(s);
        }
    }
    while(Q--){
        int n, k;
        cin >> n >> k;
        long long ans = 0;
        ans += solve(n, k);
        int lst = n;
        for(int c = n>>1; c>0; c>>=1){
            k -= len[lst];
            if(k >= 0){
                ans += k;
            }
            if(lst&1){
                ans += solve(c<<1, k-len[c<<1]);
            }
            else{
                ans += solve(2*c+1, k-len[2*c+1]);
            }
            lst = c;
        }
        cout << ans << "\n";
    }
}