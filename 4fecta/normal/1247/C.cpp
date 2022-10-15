#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

int n, p;

int bin(int n) {
    if (n <= 0) return 0;
    int ret = 0;
    while (n) {
        ret += n % 2;
        n >>= 1;
    }
    return ret;
}

int main() {
    boost();

    cin >> n >> p;
    int ans = -1;
    for (int i = 1; i <= 30; i++) {
        if (bin(n - i * p) <= i && bin(n - i * p) && (i + p) * i <= n) {
            ans = i;
            break;
        }
    }

    printf("%d\n", ans);


    return 0;
}