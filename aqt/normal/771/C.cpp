#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> graph[200005];
long long dpd[200005][6], dpc[200005][6], tempd[200005][6], tempc[200005][6];
long long ans = 0;

void dfs(int n, int p){
    dpc[n][0]++;
    for(int e : graph[n]){
        if(e != p){
            dfs(e, n);
            int t = dpc[e][0];
            for(int i = 0; i<K; i++){
                tempc[e][(i+1)%K] = dpc[e][i];
                tempd[e][(i+1)%K] = dpd[e][i];
            }
            for(int i =0; i<K; i++){
                dpc[e][i] = tempc[e][i];
                dpd[e][i] = tempd[e][i];
            }
            dpd[e][1%K] += t;
            for(int i = 0; i<K; i++){
                for(int j= 0; j<K; j++){
                    if(i+j <= K &&i && j){
                        ans -= dpc[e][i] * dpc[n][j];
                    }
                    ans += dpc[n][j]*dpd[e][i] + dpd[n][j]*dpc[e][i];
                }
            }
            for(int i = 0; i<K; i++){
                dpc[n][i] += dpc[e][i];
                dpd[n][i] += dpd[e][i];
            }
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    for(int i = 1; i<N; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1, 0);
    cout << ans << endl;
}