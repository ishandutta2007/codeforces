#include <bits/stdc++.h>

using namespace std;

int N, M;
long long arr[405];
pair<pair<int, int>, pair<int, int>> brr[250005];

int solve(int s, int e, int c, long long t){
    long long crnt = t;
    int ret = 0;
    for(int i = s+1; i<=e; i++){
        if((arr[i]-arr[i-1])*c > crnt){
            crnt = t - (arr[i]-arr[i-1])*c;
            ret++;
            if(crnt < 0){
                return INT_MAX;
            }
        }
        else{
            crnt -= (arr[i]-arr[i-1])*c;
        }
    }
    return ret;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
    }
    for(int i =1; i<=M; i++){
        cin >> brr[i].first.first >> brr[i].first.second >>
        brr[i].second.first >> brr[i].second.second;
    }
    random_shuffle(brr+1, brr+1+M);
    long long ans = 0;
    for(int i = 1; i<=M; i++){
        if(solve(brr[i].first.first, brr[i].first.second, brr[i].second.first, ans)
           > brr[i].second.second){
            long long l = ans+1, r = 2e18;
            while(l <= r){
                long long mid = l+r>>1;
                if(solve(brr[i].first.first, brr[i].first.second, brr[i].second.first, mid)
                   <= brr[i].second.second){
                    ans = mid;
                    r = mid - 1;
                   }
                else{
                    l = mid+1;
                }
            }
        }
    }
    cout << ans << endl;
}