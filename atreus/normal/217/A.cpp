#include <bits/stdc++.h>

using namespace std;

const int maxm = 1e3 + 100, maxn = 1e6 + 100;
bool mark[maxn];
int x[maxm], y[maxm], id[maxm][maxm];
pair <int, int> coor[maxn];
vector <int> v [maxn];

void dfs(int x){
    mark[x] = 1;
    for (int i = 0; i < v[x].size(); i++)
        if (!mark[v[x][i]])
            dfs(v[x][i]);
}

int main(){
    ios_base::sync_with_stdio(false);
    int n, cnt = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> x[i] >> y[i];
    for (int i = 1; i <= 1000; i++){
        for (int j = 1; j <= 1000; j++){
            id[i][j] = cnt;
            coor[cnt] = make_pair(i, j);
            cnt ++;
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (i == j)
                continue;
            if (x[i] == x[j] || y[i] == y[j])
                v[id[x[i]][y[i]]].push_back(id[x[j]][y[j]]);
        }
    }
    int q = 0;
    for (int i = 1; i <= n; i++){
        int k = id[x[i]][y[i]];
        if (!mark[k]){
            q ++;
            dfs(k);
        }
    }
    cout << --q << endl;
}