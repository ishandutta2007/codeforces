#include <bits/stdc++.h>

using namespace std;

int N, K, M = 200000;
vector<int> fre[200005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    for(int i= 1; i<=N; i++){
        int n;
        cin >> n;
        int cnt = 0;
        while(n){
            fre[n].push_back(cnt);
            n>>=1;
            cnt++;
        }
    }
    long long ans = LLONG_MAX;
    for(int i= 1; i<=M; i++){
        if(fre[i].size() >= K){
            sort(fre[i].begin(), fre[i].end());
            long long sum = 0;
            for(int j = 0; j<K; j++){
                sum += fre[i][j];
            }
            ans = min(sum, ans);
        }
    }
    cout << ans << "\n";
}