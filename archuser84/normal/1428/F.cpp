#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = l; x < r; ++x)
#define LoopR(x, l, r) for(int x = r-1; x >= l; --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << x << '\n', 0
#define YN(flag) (flag? "YES": "NO")
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("O3")
using namespace std;

const int N = 500'010;
string s;
bool a[N];
int n;

typedef vector<int> vec;

ll dc(int l, int r, vec& pre, vec& suf)
{
    if(r-l == 1)
    {
        pre.push_back(a[l]);
        suf.push_back(a[l]);
        return a[l];
    }
    int m = -1;
    int k = (l+r)/2;
    Loop(i,l+1,r)
    {
        if((!a[i] || !a[i-1]) && abs(k-i) < abs(k-m))
            m = i;
    }
    if(m == -1)
    {
        ll q = r-l;
        Loop(i,1,q+1)
            pre.push_back(i),
            suf.push_back(i);
        return (q+2)*(q+1)*q/6;
    }
    vec v1, v2;
    ll x = dc(l, m, pre, v1);
    ll y = dc(m, r, v2, suf);

    ll ans = 0;
    int p1=0, p2 = 0;
    while(p1 < v1.size())
    {
        while(p2 < v2.size() && v1[p1] >= v2[p2])
            ++p2;
        ans += (ll)(v1[p1])*(p2);
        ++p1;
    }
    p1 = 0, p2 = 0;
    while(p2 < v2.size())
    {
        while(p1 < v1.size() && v1[p1] < v2[p2])
            ++p1;
        ans += (ll)(v2[p2])*(p1);
        ++p2;
    }
    int p = pre.back();
    int s = suf.back();
    for(int x : v2)
        pre.push_back(max(p, x));
    for(int x : v1)
        suf.push_back(max(s, x));
    return x+y+ans;
}

int main()
{
    FAST;
    cin >> n;
    cin >> s;
    Loop(i,0,n)
        a[i] = s[i]-'0';
    vec tmp[2];
    cout << dc(0, n, tmp[0], tmp[1]) << '\n';
}