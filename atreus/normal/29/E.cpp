#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <iomanip>
#include <queue>
#include <time.h>
#include <set>
#include <cstring>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <bitset>
#include <unordered_set>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define In insert
using namespace std;
typedef long long ll;
const int inf = 1e9 + 7, maxn = 5e2 + 500;
bool visited[maxn][maxn][2];
int dp[maxn][maxn][2], n;
pair <pair <int, int>, bool> par[maxn][maxn][2];
vector <int> v[maxn];
queue <pair <pair <int, int>, bool> > qu;

// 0 : nobate avval - 1 : nobate avval

void bfs (int a, int b){
    visited[a][b][0] = 1;
    qu.push(MP(MP(a, b), 0));
    par[a][b][0] = MP(MP(-1, -1), 1);
    dp[a][b][0] = 0;
    while (!qu.empty()){
        int a = qu.front().F.F;
        int b = qu.front().F.S;
        int c = qu.front().S;
        if (c == 0){
            for (auto w : v[a]){
                if (!visited[w][b][1]){
                    dp[w][b][1] = dp[a][b][0];
                    qu.push(MP(MP(w, b), 1));
                    visited[w][b][1] = 1;
                    par[w][b][1] = MP(MP(a, b), 0);
                }
            }
        }
        else {
            for (auto w : v[b]){
                if (w == a)
                    continue;
                if (!visited[a][w][0]){
                    dp[a][w][0] = dp[a][b][1] + 1;
                    qu.push(MP(MP(a, w), 0));
                    visited[a][w][0] = 1;
                    par[a][w][0] = MP(MP(a, b), 1);
                }
            }
        }
        qu.pop();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    int m;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int u, w;
        cin >> u >> w;
        v[u].PB(w);
        v[w].PB(u);
    }
    memset (dp, -1, sizeof dp);
bfs (1, n);
    if (dp[n][1][0] != -1){
        cout << dp[n][1][0] << endl;
        vector <int> ans1, ans2;
        ans2.PB(1);
        int a = n, b = 1, c = 0;
        while (a != -1 and b != -1){
            if (c == 0)
                ans1.PB(a);
            else
                ans2.PB(b);
            int tmp = par[a][b][c].F.F;
            int tm = par[a][b][c].F.S;
            a = tmp;
            b = tm;
            c ^= 1;
        }
        for (int i = ans1.size() - 1; i >= 0; i--)
            cout << ans1[i] << " ";
        cout << endl;
        for (int i = ans2.size() - 1; i >= 0; i--)
            cout << ans2[i] << " ";
        cout << endl;
    }
    else
        cout << -1 << endl;
}