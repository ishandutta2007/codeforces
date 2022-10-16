#include <iostream>
#include <map>

#define NMAX 100005
#define lsb(x) ((x) & (-(x)))
#define lint long long int
using namespace std;

map <int, int> Map;
map <int, int> Map2;

struct interv {
    int st, dr;

    interv (int st = 0, int dr = 0): st(st), dr(dr) {}
} intervs[4 * NMAX];

int aib[4 * NMAX];

void upd (int pos, int val) {
    for (; pos < 4 * NMAX; pos += lsb(pos))
        aib[pos] += val;
}

int query (int pos) {
    int ans = 0;
    for (; pos; pos -= lsb(pos))
        ans += aib[pos];

    return ans;
}

int main()
{
    ios_base :: sync_with_stdio(false);

    int n = 0;
    cin >> n;

    int a, b;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;

        if (!Map[a])
            Map[a] = a;
        if (!Map[b])
            Map[b] = b;

        swap(Map[a], Map[b]);
    }

    int pos = 0;

    map <int, int> :: iterator it = Map.begin(), it2 = Map.begin();

    intervs[++ pos] = interv(it -> second, it -> second);
    Map2[it -> second] = 1;

    for (it ++; it != Map.end(); it++, it2++) {
        if (it2 -> first + 1 < it -> first) {
            intervs[++pos] = interv(it2 -> first + 1, it -> first - 1);
            Map2[it -> first - 1] = 1;
        }

        intervs[++ pos] = interv(it -> second, it -> second);
        Map2[it -> second] = 1;
    }

    int i;
    for (it = Map2.begin(), i = 1; it != Map2.end(); it++, i++)
        it -> second = i;

    for (i = 1; i <= pos; i++) {
        intervs[i].st = intervs[i].dr - intervs[i].st + 1;
        intervs[i].dr = Map2[intervs[i].dr];
    }

    lint ans = 0;
    for (int i = 1; i <= pos; i++) {
        ans += 1ll * intervs[i].st * (query(4 * NMAX - 1) - query(intervs[i].dr));
        upd(intervs[i].dr, intervs[i].st);
    }

    cout << ans << '\n';
    return 0;
}