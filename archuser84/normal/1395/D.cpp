#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = l; x < r; ++x)
#define LoopR(x, l, r) for(int x = r-1; x >= l; --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << x << '\n', 0
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

const int N = 200'010;
ll Big[N], Sml[N];
ll sumBig[N]={}; int sb = 0;
ll sumSml[N]={}; int ss = 0;
ll n, d, m;

int main()
{
    FAST;
    cin >> n >> d >> m;
    Loop(i, 0, n)
    {
        ll x;
        cin >> x;
        if(x > m)
            Big[sb++] = x;
        else
            Sml[ss++] = x;
    }
    sort(Big, Big+sb);
    sort(Sml, Sml+ss);
    reverse(Big, Big+sb);
    reverse(Sml, Sml+ss);
    Loop(i,0,sb)
        sumBig[i+1] = sumBig[i] + Big[i];
    Loop(i,sb,n)
        sumBig[i+1] = sumBig[i];
    Loop(i,0,ss)
        sumSml[i+1] = sumSml[i] + Sml[i];
    Loop(i,ss,n)
        sumSml[i+1] = sumSml[i];

    ll ans = sumSml[n];
    for(ll i = 1; i <= sb; i++)
    {
        if((i-1)*(d+1)+1 > n)
            break;
        ans = max(ans, sumBig[i] + sumSml[n-((i-1)*(d+1)+1)]);
    }
    cout << ans << '\n';
}