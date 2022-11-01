#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 300000ll;
const ll MOD = 1000000007ll;
const ll P = 259ll;

ll a[N];
bool pr[N];

vector <int> np;

main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int b, c, d;
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    string s;
    cin >> s;
    ll ans = 0;
    for (int i = 0; i < s.size(); i++)
        ans += a[(int)(s[i] - '1')];
    cout << ans;
}