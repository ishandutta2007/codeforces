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
    
    int q;
    cin >> q;
    for (; q > 0; q--) {

        double a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int x = ceil(a / c);
        int y = ceil(b / d);
        if (x + y > k) printf("-1\n");
        else printf("%d %d\n", x, y);
    }

    return 0;
}