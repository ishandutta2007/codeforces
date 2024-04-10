#include <bits/stdc++.h>
#define rf freopen("inp.in","r",stdin)
#define ll long long
#define F first
#define S second

using namespace std;

const int MAX = 500 + 50;
const int MOD = (int)(1e9 + 7);
int N , M;
int edge[MAX][MAX];
int BEST[MAX] , V[MAX];

queue < int > q;

int main(){
    
    cin.tie(0) , ios::sync_with_stdio(false);

    cin >> N >> M;
    for(int i = 1 ; i <= M ; i++){
        int u , v;
        cin >> u >> v;
        edge[u][v]++ , edge[v][u]++;
    }

    if(edge[1][N]){
        for(int i = 1 ; i <= N ; i++)
            for(int j = 1 ; j <= N ; j++)
                edge[i][j] = 1 - edge[i][j];
    }

    q.push(1);
    V[1] = 1;
    BEST[N] = -1;

    while(!q.empty()){
        
        int node = q.front();
        q.pop();

        for(int i = 1 ; i <= N ;i++)
            if(edge[node][i] && !V[i]) {
                V[i]=1;
                q.push(i);
                BEST[i] = BEST[node] + 1;
        }
    }

    cout << BEST[N] << endl;

}