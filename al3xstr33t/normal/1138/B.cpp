#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

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

const int maxN = 5016;

int n;
char s[2][maxN];
vector<int> who[4];

int a, b, c, d;
int p, q, tot;

void check() {
    //cerr << a << ' ' << b << ' ' << c << ' ' << d << '';
    if (a < 0 || b < 0 || c < 0 || d < 0) return;
    if (a > who[0].size()) return;
    if (b > who[1].size()) return;
    if (c > who[2].size()) return;
    if (d > who[3].size()) return;

    if (a + b + c + d != tot) return;
    if (d + c != p - b + q - d) return;

    while (a-- > 0) {printf("%d ", who[0].back()); who[0].pop_back();}
    while (b-- > 0) {printf("%d ", who[1].back()); who[1].pop_back();}
    while (c-- > 0) {printf("%d ", who[2].back()); who[2].pop_back();}
    while (d-- > 0) {printf("%d ", who[3].back()); who[3].pop_back();}

    exit(0);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d\n%s\n%s", &n, s[0] + 1, s[1] + 1);
    for (int i = 1; i <= n; i++)
        who[(s[0][i] - '0') * 2 + (s[1][i] - '0')].pb(i);

    p = who[1].size();
    q = who[3].size();
    tot = n / 2;

    for (d = 0; d <= tot; d++) {
        a = tot - p - q + d;
        if (a < 0 || a > tot) continue;

        for (b = 0; a + b + d <= tot; b++) {
            c = p + q - b - 2 * d;
            check();
        }
    }

    printf("-1");

    return 0;
}