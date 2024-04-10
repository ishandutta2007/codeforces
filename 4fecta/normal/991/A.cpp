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

    int a, b, c, n;
    cin >> a >> b >> c >> n;
    int pass = a + b - c;
    int res = n - pass;
    if (res <= 0 || c > b || c > a) printf("-1\n");
    else printf("%d\n", res);

    return 0;
}