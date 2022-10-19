#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 3005;

int N, M;
char mat[MAXN][MAXN];
bool z[MAXN][MAXN];
int left[MAXN][MAXN];
int right[MAXN][MAXN];
vector <pii> V[2 * MAXN];
int f[2 * MAXN];
vector <int> Q[MAXN];

void load() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++)
        scanf("%s", mat[i] + 1);
}

void update(int x, int val) {
    for (x = 2 * MAXN - x; x < 2 * MAXN; x += x & -x)
        f[x] += val;
}

int get(int x) {
    int ret = 0; 
    for (x = 2 * MAXN - x; x; x -= x & -x)
        ret += f[x];
    return ret;
}

int calc(const vector <pii> &vals) {
    if (vals.empty()) return 0;
    
    for (int i = 0; i < vals.size(); i++) 
        Q[max(i - vals[i].second + 1, 0)].push_back(i);
    
    int res = 0;
    for (int i = 0; i < vals.size(); i++) {
        for (; !Q[i].empty(); Q[i].pop_back())
            res -= get(Q[i].back() + 1);
        update(vals[i].first + i, 1);
        res += get(i + 1);
    }
    
    for (int i = 0; i < vals.size(); i++)
        update(vals[i].first + i, -1);
    
    return res;
} 

ll solve() {
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            z[i][j] = mat[i][j] == 'z';
            
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            left[i][j] = (left[i][j - 1] + 1) * z[i][j];
    
    for (int i = 1; i <= N; i++)
        for (int j = M; j; j--)
            right[i][j] = (right[i][j + 1] + 1) * z[i][j];
    
    ll sol = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            if (z[i][j]) 
                V[i + j].push_back(pii(left[i][j], right[i][j]));
            else {
                sol += calc(V[i + j]);
                V[i + j].clear();
            }
            
    for (int i = 1; i <= N + M; i++)
        sol += calc(V[i]);
    
    return sol;
}

int main() {
    load();
    printf("%I64d\n", solve());
    return 0;
}