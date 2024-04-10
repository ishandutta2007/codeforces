//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>


using namespace std;


using ll = long long;
using ld = long double;

#define X first
#define Y second

const ll mod = 1000000007;
//const ll mod = 998244353;

vector<vector<pair<ll,ll>>> mxA, mxB;
vector<ll> A, B;
vector<ll> len;
ll K = 20;
ll n;

void calc(ll L, ll R)
{
    R++;
    ll b = len[R-L];
    ll L2 = R-(1LL<<b);
    ll x1, y1 = 2*n, p, x2, y2 = 2*n;
    if (A[mxA[L][b].X]>A[mxA[L2][b].X])
    {
        x1 = mxA[L][b].X;
    } else x1 = mxA[L2][b].X;
    p = mxA[L][b].X;
    if (x1!=p and A[y1]<A[p]) y1 = p;
    p = mxA[L][b].Y;
    if (x1!=p and A[y1]<A[p]) y1 = p;
    p = mxA[L2][b].X;
    if (x1!=p and A[y1]<A[p]) y1 = p;
    p = mxA[L2][b].Y;
    if (x1!=p and A[y1]<A[p]) y1 = p;
    if (B[mxB[L][b].X]>B[mxB[L2][b].X])
    {
        x2 = mxB[L][b].X;
    } else x2 = mxB[L2][b].X;
    p = mxB[L][b].X;
    if (x2!=p and B[y2]<B[p]) y2 = p;
    p = mxB[L][b].Y;
    if (x2!=p and B[y2]<B[p]) y2 = p;
    p = mxB[L2][b].X;
    if (x2!=p and B[y2]<B[p]) y2 = p;
    p = mxB[L2][b].Y;
    if (x2!=p and B[y2]<B[p]) y2 = p;
    if (x1!=x2)
    {
        cout << A[x1]+B[x2] << "\n";
        return;
    }
    ll ans = A[x1]+B[y2];
    ll ans2 = A[y1]+B[x2];
    cout << max(ans,ans2) << "\n";
}

void solve()
{
    ll m;
    cin >> n >> m;
    vector<ll> d(n), h(n);
    for (ll i=0;i<n;i++)
    {
        cin >> d[i];
    }
    for (ll i=0;i<n;i++)
    {
        cin >> h[i];
        h[i]*=2;
    }
    A.resize(n*2+1);
    B.resize(n*2+1);
    for (ll i=0;i+1<2*n;i++)
    {
        A[i+1] = A[i]+d[i%n];
        B[i+1] = B[i]-d[i%n];
    }
    A[2*n] = B[2*n] = -mod*mod;
    mxA.resize(2*n,vector<pair<ll,ll>> (K));
    mxB.resize(2*n,vector<pair<ll,ll>> (K));
    for (ll i=0;i<2*n;i++)
    {
        A[i] += h[i%n];
        B[i] += h[i%n];
        mxA[i][0].X = i;
        mxB[i][0].X = i;
        mxA[i][0].Y = 2*n;
        mxB[i][0].Y = 2*n;
    }
    {
        len.resize(2*n+1);
        ll q = 0;
        for (ll w=1;w<=2*n;w++)
        {
            if ((1LL<<q)*2==w) q++;
            len[w] = q;
        }
    }

    for (ll j=1;j<K;j++)
    {
        for (ll i=0;i+(1LL<<j)<=2*n;i++)
        {
            ll i2 = i+(1LL<<(j-1));
            if (A[mxA[i][j-1].X]>A[mxA[i2][j-1].X])
            {
                mxA[i][j].X = mxA[i][j-1].X;
                if (A[mxA[i][j-1].Y]>A[mxA[i2][j-1].X])
                {
                    mxA[i][j].Y = mxA[i][j-1].Y;
                } else mxA[i][j].Y = mxA[i2][j-1].X;
            }
            else
            {
                mxA[i][j].X = mxA[i2][j-1].X;
                if (A[mxA[i][j-1].X]>A[mxA[i2][j-1].Y])
                {
                    mxA[i][j].Y = mxA[i][j-1].X;
                } else mxA[i][j].Y = mxA[i2][j-1].Y;
            }
            if (B[mxB[i][j-1].X]>B[mxB[i2][j-1].X])
            {
                mxB[i][j].X = mxB[i][j-1].X;
                if (B[mxB[i][j-1].Y]>B[mxB[i2][j-1].X])
                {
                    mxB[i][j].Y = mxB[i][j-1].Y;
                } else mxB[i][j].Y = mxB[i2][j-1].X;
            }
            else
            {
                mxB[i][j].X = mxB[i2][j-1].X;
                if (B[mxB[i][j-1].X]>B[mxB[i2][j-1].Y])
                {
                    mxB[i][j].Y = mxB[i][j-1].X;
                } else mxB[i][j].Y = mxB[i2][j-1].Y;
            }
        }
    }
    while (m--)
    {
        ll L, R;
        cin >> L >> R;
        L--, R--;
        if (L<=R) calc(R+1,L-1+n);
        else calc(R+1,L-1);
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    ll T;
    T = 1;
    //cin >> T;
    while (T--) solve();
}