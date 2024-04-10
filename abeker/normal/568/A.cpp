#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

const int MAXN = 2000005;

int P, Q;
bool np[MAXN];

void load() {
    scanf("%d%d", &P, &Q);
}

bool pal(int x) {
    vector <int> d, t;
    for (; x; x /= 10)
        d.push_back(x % 10);
    t = d;
    reverse(t.begin(), t.end());
    return t == d;
}

void solve() {
    np[1] = true;
    for (int i = 1; i < MAXN; i++) {
        if (np[i]) continue;
        for (int j = 2 * i; j < MAXN; j += i)
            np[j] = true;
    }
    
    int pi = 0, rub = 0, sol = 0;
    for (int i = 1; i < MAXN; i++) {
        pi += !np[i];
        rub += pal(i);
        if ((ll)Q * pi <= (ll)P * rub) sol = i;
    }
    
    if (sol) printf("%d\n", sol);
    else puts("Palindromic tree is better than splay tree");
}

int main() {
    load();
    solve();
    return 0;
}