#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(), vr.end()

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

const int N = 1e5 + 10;
int a[N], n;

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int sum = 0;
        for (int i = 1; i <= n; ++i) cin >> a[i], sum += a[i];
        int flag = 0;
        for (int i = 2; i * i <= sum; ++i)
            if (sum % i == 0)
            {
                flag = 1;
                break;
            }
        if (flag)
        {
            cout << n << "\n";
            for (int i = 1; i <= n; ++i) cout << i << " ";
            cout << "\n";
            continue;
        }
        cout << n - 1 << "\n";
        flag = 0;
        for (int i = 1; i <= n; ++i)
            if (a[i] % 2 == 0 || flag) cout << i << " ";
            else flag = 1;
        cout << "\n";
    }
    return 0;
}