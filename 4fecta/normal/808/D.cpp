#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 100005;

int n; ll a[MN], psa[MN], sum = 0;
set<ll> s;

int main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        psa[i] = psa[i - 1] + a[i];
        sum += a[i];
    }
    if (sum % 2) {printf("NO\n"); return 0;}
    sum /= 2;
    s.insert(0);
    for (int i = n; i > 0; i--) {
        ll want = sum - psa[i];
        if (s.count(want)) {printf("YES\n"); return 0;}
        if (a[i] == sum){printf("YES\n"); return 0;}
        s.insert(a[i]);
    }
    s.clear();
    s.insert(0);
    for (int i = 1; i <= n; i++) {
        ll want = sum - psa[n] + psa[i - 1];
        if (s.count(want)) {printf("YES\n"); return 0;}
        s.insert(a[i]);
    }
    printf("NO\n");

    return 0;
}