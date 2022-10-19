#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 500005;

int N;
int a[MAXN];
pii p[MAXN];
set <int> S;

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", a + i);
}

ll solve() {
    for (int i = 0; i < N; i++)
        p[i] = pii(a[i], i);
    sort(p, p + N);
	
    for (int i = 0; i < N; i++)
        S.insert(i);
	
    ll sol = 0;
    int mx1 = 0, mx2 = 0;
    for (int i = 0; i < N; i++) {
        set <int> :: iterator it = S.find(p[i].second);
        if (it != S.begin() && it != --S.end()) {
            int l = a[*(--it)]; it++;
            int r = a[*(++it)]; it--;
            sol += (ll)min(l, r);
        }
        else {
            int tmp = p[i].first;
            sol += (ll)tmp;
            if (tmp >= mx1) {
                mx2 = mx1;
                mx1 = tmp;
            }
            else if (tmp > mx2)
                mx2 = tmp;
        }
        S.erase(it);
    }
    sol -= (ll)(mx1 + mx2);
	
    return sol;
}

int main() {
    load();
    printf("%I64d\n", solve());
    return 0;
}