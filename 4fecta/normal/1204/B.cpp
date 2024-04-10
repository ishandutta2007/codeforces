#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

int n, l, r;

int main() {
    boost();

    cin >> n >> l >> r;
    int mi[n];
    int mx[n];
    mi[0] = mx[0] = 1;
    int d = 1;
    int s1 = 1;
    int s2 = 1;
    for (int i = 1; i < n; i++) {
        if (d < r) {
            mx[i] = mx[i - 1] * 2;
            d++;
        } else {
            mx[i] = mx[i - 1];
        }
        //printf("%d ", mx[i]);
        s1 += mx[i];
    }
    //printf("\n");
    for (int i = 1; i < n; i++) {
        if (n - i < l) {
            mi[i] = mi[i - 1] * 2;
        } else {
            mi[i] = mi[i - 1];
        }
        //printf("%d ", mi[i]);
        s2 += mi[i];
    }
    //printf("\n");
    printf("%d %d\n", s2, s1);

    return 0;
}