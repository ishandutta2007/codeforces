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

bool check(double x)
{
    int r = sqrt(x);
    return ((ll)r*r==x);
}

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        double n;
        cin >> n;
        if (check(n / 2) || check(n / 4)) cout <<"YES\n";
        else cout << "NO\n";
    }
    return 0;
}