#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 500005;

int N;
int a[MAXN];
vector <pii> V;

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", a + i);
}

void solve() {
    int last = 0;
    for (int i = 0; i < N; i++) 
        if (i && a[i] != a[i - 1]) {
            V.push_back(pii(last, i));
            last = i;
        }
    V.push_back(pii(last, N + 1));
    
    last = 0;
    int sol = 0;
    for (int i = 1; i < V.size(); i++)
        if (V[i].second - V[i].first > 1) {
            int len = V[i].first - V[last].second;
            sol = max(sol, (len + 1) / 2);
            for (int j = 0; j < (len + 1) / 2; j++)
                a[V[last].second + j] = a[V[last].second - 1];
            for (int j = 1; j <= len / 2; j++)
                a[V[i].first - j] = a[V[i].first]; 
            last = i;
        }
        
    printf("%d\n", sol);
    for (int i = 0; i < N; i++)
        printf("%d ", a[i]);
    puts("");
}

int main() {
    load();
    solve();
    return 0;
}