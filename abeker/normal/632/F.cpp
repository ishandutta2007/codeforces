#include <cstdio>
#include <algorithm>
#include <bitset>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 2505;

int N;
int a[MAXN][MAXN];
bitset <MAXN> mask[MAXN];
vector <pii> V;

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", a[i] + j);
}

bool cmp(const pii &l, const pii &r) {
    return a[l.first][l.second] < a[r.first][r.second];
}

bool solve() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            V.push_back(pii(i, j));
            if (a[i][j] != a[j][i]) return false;
            if (i == j && a[i][j]) return false;
        }
        
    sort(V.begin(), V.end(), cmp);
    
    int j = 0;
    for (int i = 0; i < V.size(); i++) { 
        for (; j < V.size() && !cmp(V[i], V[j]) && !cmp(V[j], V[i]); j++)
            if ((mask[V[j].first] & mask[V[j].second]).any()) 
                return false;
        for (int k = i; k < j; k++)
            mask[V[k].first].set(V[k].second);
        i = j;
    }            
    
    return true;
}

int main() {
    load();
    puts(solve() ? "MAGIC" : "NOT MAGIC");
    return 0;
}