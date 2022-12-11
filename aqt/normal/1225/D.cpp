#include <bits/stdc++.h>

using namespace std;

int N, K;
map<vector<pair<int, int>>, int> mp;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    long long ans = 0;
    for(int i = 1; i<=N; i++){
        int n;
        cin >> n;
        vector<pair<int, int>> v;
        for(int i = 2; i<=sqrt(n); i++){
            if(n%i == 0){
                int cnt = 0;
                while(n%i == 0){
                    cnt++;
                    n /= i;
                }
                if(cnt%K != 0){
                    v.push_back({i, cnt%K});
                }
            }
        }
        if(n != 1){
            v.push_back({n, 1});
        }
        vector<pair<int, int>> t;
        for(auto p : v){
            t.push_back({p.first, (K-p.second)%K});
        }
        ans += mp[t];
        mp[v]++;
    }
    cout << ans << endl;
}