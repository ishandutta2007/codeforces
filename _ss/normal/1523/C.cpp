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

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi vt;
        for (int i = 1, x; i <= n; ++i)
        {
            cin >> x;
            if (x == 1) vt.eb(1);
            else
            {
                while (vt.back() != x - 1) vt.pop_back();
                vt.back()++;
            }
            cout << vt[0];
            for (int j = 1; j < (int)vt.size(); ++j) cout << "." << vt[j];
            cout << "\n";
        }
    }
    return 0;
}