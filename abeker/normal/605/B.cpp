#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 100005;

int N, M;
pii sol[MAXN];
vector <pii> yes, no;
int deg[MAXN];

void load() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (b) yes.push_back(pii(a, i));
        else no.push_back(pii(a, i)); 
    }    
}

void solve() {
    sort(yes.begin(), yes.end());
    sort(no.begin(), no.end());
    
    for (int i = 0; i < yes.size(); i++) {
        sol[yes[i].second] = pii(i, N - 1);
        deg[i] = i;
    }
    
    int pos = N - 2;
    for (int i = (int)no.size() - 1; i >= 0; i--) {
        for (; pos >= 0 && (no[i].first < yes[pos].first || !deg[pos]); pos--);
        if (pos < 0) {
            puts("-1");
            return;
        }
        sol[no[i].second] = pii(pos, --deg[pos]);
    }
    
    for (int i = 0; i < M; i++)
        printf("%d %d\n", ++sol[i].first, ++sol[i].second);
}

int main() {
    load();
    solve();
    return 0;
}