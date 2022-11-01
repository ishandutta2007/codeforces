#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
typedef unsigned long long ui64;

#define checkbit(n, b) ((n >> b) & 1)
#define gcd __gcd
#define bitcount __bultin_popcount
#define inf (int)1e9
#define eps 1e-9
#define pi acos(-1)
#define mod 1000000007
#define buff 100

int main() {
    ios_base::sync_with_stdio(false);
    i64 a, b, s; cin >> a >> b >> s;
    if (abs(a) + abs(b) > s) cout << "No\n";
    else if ((s - abs(a) - abs(b)) % 2) cout << "No\n";
    else cout << "Yes\n";
    return 0;
}