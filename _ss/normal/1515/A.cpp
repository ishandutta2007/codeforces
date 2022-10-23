#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(),vr.end()
#define vi vector<int>
#define vll vector<ll>
const int N = 1e5 + 10;
int a[N];

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        sort(a+1, a+n+1);
        int sum = 0, flag = 1;
        for (int i=1;i<=n;i++)
        {
            sum += a[i];
            if (sum == x)
            {
                if (i == n) flag = 0;
                else swap(a[n], a[i]);
                break;
            }
        }
        if (flag)
        {
            cout << "YES\n";
            for (int i = 1; i <= n; ++i) cout << a[i] << " ";
            cout << "\n";
        }
        else cout << "NO\n";
    }
    return 0;
}