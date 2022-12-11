#include <bits/stdc++.h>

using namespace std;

int dp[1<<20];
int N, M;
map<string, int> mp;
string s;
vector<long long> seg;
long long graph[40];

int main(){
    cin >> N >> M;
    long long m = 0;
    int cnt = 0;
    fill(graph, graph+M, (1LL<<M)-1);
    for(int i = 1; i<=N; i++){
        int c;
        cin >> c;
        if(c == 1){
            for(int k = 0; k<M; k++){
                if((1LL<<k)&m){
                    graph[k] &= ~m;
                }
            }
            m = 0;
        }
        else{
            cin >> s;
            if(!mp.count(s)){
                mp[s] = cnt++;
            }
            m |= (1LL<<mp[s]);
        }
    }
    for(int k = 0; k<M; k++){
        if((1LL<<k)&m){
            graph[k] &= ~m;
        }
    }
    for(int k = 0; k<M; k++){
        graph[k] |= (1LL<<k);
    }
    m = 0;
    for(int k = 0; k<1LL<<20; k++){
        m = (1LL<<M)-1;
        for(int b = 0; b<20; b++){
            if((1LL<<b)&k){
                m &= graph[b];
                dp[k] = max(dp[k], dp[k^(1LL<<b)]);
            }
        }
        if((m&k) == k){
            dp[k] = __builtin_popcountll(k);
        }
    }
    int ans = dp[(1<<20)-1];
    if(M > 20){
        for(long long k = 0; k<1LL<<(M-20); k++){
            m = (1LL<<M)-1;
            for(int b = 0; b<M-20; b++){
                if((1LL<<b)&k){
                    m &= graph[b+20];
                }
            }
            if((m&(k<<20)) == k<<20){
                ans = max(ans, dp[((1LL<<20)-1)&(m)] + __builtin_popcountll(k));
            }
        }
    }
    cout << ans << endl;
}