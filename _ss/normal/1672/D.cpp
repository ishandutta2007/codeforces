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

const int N = 2e5 + 10;
int n, a[N], b[N], cnt[N];

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
        for (int i = 1; i <= n; ++i) cin >> b[i], cnt[i] = 0;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        int j = 1, prv = -1;
        bool check = true;
        for (int i = 1; i <= n; ++i)
        {
            if (j <= n && a[i] == b[j])
            {
                j++;
                prv = a[i];
                continue;
            }
            if (prv == a[i] && cnt[a[i]])
            {
                cnt[a[i]]--;
                continue;
            }
            while (j <= n && a[i] != b[j])
            {
                cnt[b[j]]++;
                j++;
            }
            if (j > n)
            {
                check = false;
                break;
            }
            prv = a[i];
            j++;
        }
        if (check) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}