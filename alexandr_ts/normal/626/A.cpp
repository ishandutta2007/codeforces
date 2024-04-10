#include <bits/stdc++.h>
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define fr(i, n) for (ll i = 0; i < n; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pr;

const ll M = 2e4 + 10;
const ll INF = 2e9 + 10;
const ll N = 2e5 + 10;
const ll MOD = 1e9 + 7;

char ch[N];
int l[N], r[N];

int main() {
    //freopen("sweets.in", "r", stdin);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    fr(l, n)
        frab(r, l, n) {
            int b1 = 0, b2 = 0;
            frab(i, l, r + 1)
                if (s[i] == 'U')
                    b1++;
                else if (s[i] == 'D')
                    b1--;
                else if (s[i] == 'L')
                    b2++;
                else if (s[i] == 'R')
                    b2--;
            if (!b1 && !b2)
                ans++;
        }
    cout << ans;

}