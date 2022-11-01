#include <algorithm>
#include <iostream>
#include <assert.h>
#include <sstream>
#include <complex>
#include <numeric>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)          (a).begin(), (a).end()
#define sz(a)           int((a).size())
#define FOR(i, a, b)    for (int i(a); i < b; ++i)
#define REP(i, n)       FOR(i, 0, n)
#define UN(v)           sort(all(v)), (v).erase(unique((v).begin(), (v).end()), (v).end())
#define CL(a, b)        memset(a, b, sizeof a)
#define pb              push_back
#define X               first
#define Y               second

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

int n, m, need;
char s[555][555];
bool b[555][555];

int dd[] = {-1, 0, 1, 0};

vector<pii> path;

void dfs(int x, int y)
{
    b[x][y] = true;
    REP (k, 4)
    {
        uint32_t nx = x + dd[k], ny = y + dd[k ^ 1];
        if (nx < n && ny < m && s[nx][ny] == '.' && !b[nx][ny])
            dfs(nx, ny);
    }
    if (need > 0)
    {
        --need;
        s[x][y] = 'X';
    }
}

int main() {
    #ifdef LocalHost
    freopen("x.in", "r", stdin);
    #endif
    cin >> n >> m >> need;
    REP (i, n) cin >> s[i];
    REP (i, n) REP (j, m) if (s[i][j] == '.')
    {
        dfs(i, j);
        break;
    }
    REP (i, n) puts(s[i]);
    return 0;
}