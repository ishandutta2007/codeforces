#include <bits/stdc++.h>

using namespace std;

int N, M;
long long MOD = 1915442707;
long long sd = 43;
long long pows[300005];
vector<int> graph[300005];
long long cache[300005];
int ans[300005];
map<int, vector<int>> mp;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for(int i = 1; i<=M; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    pows[0] = 1;
    for(int i = 1; i<=N; i++){
        pows[i] = pows[i-1]*sd;
        pows[i] %= MOD;
    }
    for(int n = 1; n<=N; n++){
        long long hsh = 0;
        for(int e : graph[n]){
            hsh += pows[e];
            hsh %= MOD;
        }
        cache[n] = hsh;
        mp[(int) hsh].push_back(n);
    }
    if(mp.size() != 3){
        cout << -1 << "\n";
        return 0;
    }
    int cnt = 0;
    for(auto p : mp){
        cnt++;
        for(int n : p.second){
            ans[n] = cnt;
        }
    }
    for(int n = 1; n<=N; n++){
        cout << ans[n] << " ";
    }
}