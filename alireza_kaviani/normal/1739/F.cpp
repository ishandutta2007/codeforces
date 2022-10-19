#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)      (x).begin(),(x).end()
#define X           first
#define Y           second
#define sep         ' '
#define endl        '\n'
#define SZ(x)       ll(x.size())

const ll MAXN = 4010; // TODO
const ll LOG = 12;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , trieInd , C[MAXN] , mark[MAXN] , nxt[MAXN][LOG] , F[MAXN] , val[MAXN] , dp[1 << LOG][MAXN] , par[1 << LOG][MAXN];
string s[MAXN] , t;
set<int> adj[LOG];

void DFS(int v){
    mark[v] = 1;
    t.push_back(v + 'a');
    for(int u : adj[v]){
        if(!mark[u]){
            DFS(u);
        }
    }
}

int insert(string s , int c){
    int cur = 0;
    for(int i = 0 ; i < SZ(s) ; i++){
        int ch = s[i] - 'a';
        if(nxt[cur][ch] == 0){
            nxt[cur][ch] = ++trieInd;
        }
        cur = nxt[cur][ch];
    }
    val[cur] += c;
    return cur;
}
 
void buildAho(){
    queue<int> Q;
    Q.push(0);
    while(!Q.empty()){
        int v = Q.front(); Q.pop();
        if(v != 0){
            val[v] += val[F[v]];
        }
        for(int i = 0 ; i < LOG ; i++){
            if(nxt[v][i] == 0){
                nxt[v][i] = nxt[F[v]][i];
            }
            else{
                F[nxt[v][i]] = (v == 0 ? 0 : nxt[F[v]][i]);
                Q.push(nxt[v][i]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> C[i] >> s[i];
        fill(adj , adj + LOG , set<int>());
        fill(mark , mark + LOG , 1);
        t.clear();
        for(int j = 0 ; j + 1 < SZ(s[i]) ; j++){
            int v = s[i][j] - 'a' , u = s[i][j + 1] - 'a';
            adj[v].insert(u);
            adj[u].insert(v);
            mark[v] = mark[u] = 0;
        }
        int flag = 0;
        for(int j = 0 ; j < LOG ; j++){
            if(SZ(adj[j]) > 2){
                flag = 1;
            }
        }
        if(flag){
            continue;
        }
        for(int j = 0 ; j < LOG ; j++){
            if(SZ(adj[j]) == 1){
                DFS(j);
                break;
            }
        }
        insert(t , C[i]);
        if(SZ(t) > 1){
            reverse(all(t));
            insert(t , C[i]);
        }
    }
    buildAho();
    for(int i = 0 ; i <= trieInd ; i++){
        dp[0][i] = val[i];
    }
    for(int i = 1 ; i < (1 << LOG) ; i++){
        for(int j = 0 ; j <= trieInd ; j++){
            dp[i][j] = -MOD;
            for(int k = 0 ; k < LOG ; k++){
                if(i & (1 << k)){
                    ll x = val[j] + dp[i ^ (1 << k)][nxt[j][k]];
                    if(x > dp[i][j]){
                        dp[i][j] = x;
                        par[i][j] = k;
                    }
                }
            }
        }
    }

    int cur = (1 << LOG) - 1 , node = 0;
    string ans;
    for(int i = 0 ; i < LOG ; i++){
        int ch = par[cur][node];
        ans.push_back(ch + 'a');
        node = nxt[node][ch];
        cur ^= (1 << ch);
    }
    cout << ans << endl;

    return 0;
}
/*

*/