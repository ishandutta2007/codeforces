#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(), vr.end()
#define vi vector<int>
#define vll vector<ll>
const int N = 1e5 + 10;
int a[N], n, k;

int And(int i, int j)
{
    cout << "and " << i << " " << j << endl;
    int res;
    cin >> res;
    return res;
}

int Or(int i, int j)
{
    cout << "or " << i << " " << j << endl;
    int res;
    cin >> res;
    return res;
}

int main()
{
    //freopen("ss.inp", "r", stdin);
    cin.tie(0);
    cin >> n >> k;
    int o12 = Or(1, 2), o13 = Or(1, 3);
    int a12 = And(1, 2), a13 = And(1, 3);
    a[1] = o12 & o13;
    int a23 = And(2, 3);
    a[1] ^= a23;
    a[1] ^= (a12 & a13);
    a[2] = a[1] ^ (o12 - a12);
    a[3] = a[1] ^ (o13 - a13);
    for (int i = 4; i <= n; ++i) a[i] = a[1] ^ (Or(1, i) - And(1, i));
    sort(a + 1, a + n + 1);
    cout << "finish " << a[k] << endl;
    return 0;
}