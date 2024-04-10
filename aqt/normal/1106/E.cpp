#include <bits/stdc++.h>

using namespace std;

struct envelope{
    int lft, rht, nxt, val;
    bool operator <(const envelope& e) const{
        if(val == e.val){
            return e.nxt > nxt;
        }
        return e.val > val;
    }
};

int N, K, M;
long long dp[100005][205];
int lft[100005], rht[100005], nxt[100005], val[100005];
vector<int> add[100005], rem[100005];
priority_queue<envelope> pq;
bool tkn[100005];

int main(){
    scanf("%d %d %d", &N, &K, &M);
    for(int i = 1; i<=M; i++){
        scanf("%d %d %d %d", &lft[i], &rht[i], &nxt[i], &val[i]);
        add[lft[i]].push_back(i);
        rem[rht[i]].push_back(i);
    }
    for(int i = 0; i<=N+1; i++){
        for(int j = 0; j<=K; j++){
            dp[i][j] = LLONG_MAX>>1;
        }
    }
    dp[0][0] = 0;
    for(int i = 0; i<=N; i++){
        for(int n : add[i]){
            pq.push({lft[n], rht[n], nxt[n], val[n]});
        }
        for(int j = 0; j<=K; j++){
            if(dp[i][j] != LLONG_MAX >> 1){
                if(pq.empty()){
                    dp[i+1][j] = min(dp[i][j], dp[i+1][j]);
                }
                else{
                    dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]);
                    dp[pq.top().nxt+1][j] = min(dp[pq.top().nxt+1][j], dp[i][j] + pq.top().val);
                }
            }
        }
        while(pq.size() && pq.top().rht <= i){
            pq.pop();
        }
    }
    long long ans = LLONG_MAX >> 1;
    for(int i = 0; i<=K; i++){
        ans = min(dp[N+1][i], ans);
    }
    cout << ans << endl;
}