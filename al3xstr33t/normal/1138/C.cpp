#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

//#define debug(x) ;
#define debug(x) cerr << #x << " = " << x << "\n";

ostream& operator<<(ostream& cerr, vector<ll> aux) {
    cerr << "[";
    for (auto e : aux) cerr << e << ' ';
    cerr << "]";
    return cerr;
}

const int maxN = 1024;

int n, m;
int mat[maxN][maxN];
vector<int> aux;

int lns[maxN][maxN], cols[maxN][maxN];
int cnt_ln[maxN], cnt_col[maxN];
map<int, int> M;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) 
            scanf("%d", &mat[i][j]);
    }

    for (int i = 1; i <= n; i++) {
        aux.clear();

        for (int j = 1; j <= m; j++) aux.pb(mat[i][j]);
        sort(aux.begin(), aux.end());
        aux.resize(unique(aux.begin(), aux.end()) - aux.begin());

        M.clear();
        cnt_ln[i] = 0;
        for (auto e : aux) M[e] = ++cnt_ln[i];

        for (int j = 1; j <= m; j++) lns[i][j] = M[mat[i][j]];
    }


    for (int j = 1; j <= m; j++) {
        aux.clear();

        for (int i = 1; i <= n; i++) aux.pb(mat[i][j]);
        sort(aux.begin(), aux.end());
        aux.resize(unique(aux.begin(), aux.end()) - aux.begin());

        M.clear();
        cnt_col[j] = 0;
        for (auto e : aux) M[e] = ++cnt_col[j];

        for (int i = 1; i <= n; i++) cols[i][j] = M[mat[i][j]];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int pre = max(cols[i][j], lns[i][j]);
            int post = max(cnt_col[j] - cols[i][j], cnt_ln[i] - lns[i][j]);
            printf("%d ", pre + post);
        }
        printf("\n");
    }


    return 0;
}