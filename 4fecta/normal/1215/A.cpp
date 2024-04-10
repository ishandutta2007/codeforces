#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

int main() {
    boost();

    int a1, a2, p1, p2, n;
    cin >> a1 >> a2 >> p1 >> p2 >> n;
    int ta1 = a1, ta2 = a2, tp1 = p1, tp2 = p2, tn = n;
    if (p2 > p1) {
        swap(a2, a1);
        swap(p2, p1);
    }
    int mx = 0, mi = 0;
    while (n >= p2 && a2 > 0) {
        mx++;
        n -= p2;
        a2--;
    }
    while (n >= p1 && a1 > 0) {
        mx++;
        n -= p1;
        a1--;
    }

    int tmp = (ta1 * (tp1 - 1)) + (ta2 * (tp2 - 1));
    //printf("%d\n", tmp);
    mi = max(0, tn - tmp);

    printf("%d %d\n", mi, mx);

    return 0;
}