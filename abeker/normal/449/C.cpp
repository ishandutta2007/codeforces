#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 100005;

int N;
vector <int> p;
vector < pii > sol;
bool c[MAXN], bio[MAXN];

void load() {
    scanf("%d", &N);
}

void init() {
    for (int i = 2; i <= N; i++) {
        if (c[i]) continue;
        p.push_back(i);
        for (int j = i; j <= N; j += i) 
            c[j] = true;
    }
}

void add(int a, int b) {
    bio[a] = bio[b] = true;
    sol.push_back(pii(a, b));
}

void solve() {
    for (int i = (int)p.size() - 1; i >= 0; i--) {
        if (2 * p[i] > N) continue;
        vector <int> tmp;
        for (int j = p[i]; j <= N; j += p[i])
            if (!bio[j]) tmp.push_back(j);
        if (tmp.size() % 2) tmp.erase(tmp.begin() + 1);
        for (int j = 0; j < tmp.size(); j += 2) 
            add(tmp[j], tmp[j + 1]);
    }
    printf("%d\n", sol.size());
    for (int i = 0; i < sol.size(); i++)
        printf("%d %d\n", sol[i].first, sol[i].second);
}

int main() {
    load();
    init();
    solve();
    return 0;
}