#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
#define X first
#define Y second

ll mod = 998244353;

ll gcd(ll a, ll b)
{
    if (a==0 or b==0) return a+b;
    return gcd(b,a%b);
}

ll sum(ll a, ll b)
{
    a += b;
    a %= mod;
    return a;
}

ll sub(ll a, ll b)
{
    a += mod-b;
    a %= mod;
    return a;
}

ll mul(ll a, ll b)
{
    return a*b%mod;
}

ll pew(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b&1) res = mul(res,a);
        a = mul(a,a);
        b /= 2;
    }
    return res;
}

/*
typedef complex<double> base;
long double PI = acos(-1);
const ll root = 31;
const ll root_pw = 1<<23;
void fft (vector<base> & a, bool invert) {
    int n = (int) a.size();
    if (n == 1)  return;

    vector<base> a0 (n/2),  a1 (n/2);
    for (int i=0, j=0; i<n; i+=2, ++j) {
        a0[j] = a[i];
        a1[j] = a[i+1];
    }
    fft (a0, invert);
    fft (a1, invert);

    double ang = 2*PI/n * (invert ? -1 : 1);
    base w (1),  wn (cos(ang), sin(ang));
    for (int i=0; i<n/2; ++i) {
        a[i] = a0[i] + w * a1[i];
        a[i+n/2] = a0[i] - w * a1[i];
        if (invert)
            a[i] /= 2,  a[i+n/2] /= 2;
        w *= wn;
    }
}
*/
int parent[600001];
int rnk[600001];
int suk[600001];

void make_set (int v) {
    parent[v] = v;
    rnk[v] = 0;
    suk[v] = 0;
}

int find_set (int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    if (a != b and (suk[a]*suk[b]==0)) {
        if (rnk[a] < rnk[b])
            swap(a, b);
        parent[b] = a;
        if (rnk[a] == rnk[b])
            ++rnk[a];
        suk[a] += suk[b];
    }
}

/*
ll t[1200000];

void build()
{
    for (int i=0;i<1200000;i++)
    {
        t[i] = 0;
    }
}

void update (int v, int tl, int tr, int l, int r, ll val) {
    if (tl==l and tr==r)
    {
        t[v] += val;
        return;
    }
    int tm = (tl + tr) / 2;
    if (r<=tm)
    {
        update(2*v,tl,tm,l,r,val);
        return;
    }
    if (l>tm)
    {
        update(2*v+1,tm+1,tr,l,r,val);
        return;
    }
    update(2*v,tl,tm,l,tm,val);
    update(2*v+1,tm+1,tr,tm+1,r,val);
}

ll get (int v, int tl, int tr, int pos) {
    if (tl == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    if (pos<=tm) return get(2*v,tl,tm,pos)+t[v];
    if (pos>tm) return get(2*v+1,tm+1,tr,pos)+t[v];
}*/

/*
ll base = 1000000000;

vector<ll> mul(vector<ll> a, vector<ll> b)
{
    vector<ll> res(a.size()+b.size());
    for (int i=0;i<a.size();i++)
    {
        for (int j=0;j<b.size();j++)
        {
            res[i+j] += a[i]*b[j];
        }
    }
    for (int i=0;i<res.size();i++)
    {
        if (res[i]>base)
        {
            res[i+1] += res[i]/base;
            res[i] %= base;
        }
    }
    for (int i=res.size()-1;i>0;i--)
    {
        if (res[i]==0)
        {
            res.pop_back();
        }
        else
        {
            break;
        }
    }
    return res;
}

vector<ll> sum(vector<ll> a, vector<ll> b)
{
    if (a.size()<b.size())
    {
        swap(a,b);
    }
    vector<ll> res(a.size()+b.size());
    for (int i=0;i<b.size();i++)
    {
        res[i] += a[i]+b[i];
    }
    for (int i=b.size();i<a.size();i++)
    {
        res[i] = a[i];
    }
    for (int i=0;i<res.size();i++)
    {
        if (res[i]>base)
        {
            res[i+1] += res[i]/base;
            res[i] %= base;
        }
    }
    for (int i=res.size()-1;i>0;i--)
    {
        if (res[i]==0)
        {
            res.pop_back();
        }
        else
        {
            break;
        }
    }
    return res;
}

vector<ll> sub(vector<ll> a, vector<ll> b)
{
    vector<ll> res(a.size()+b.size());
    for (int i=0;i<b.size();i++)
    {
        res[i] += a[i]-b[i];
    }
    for (int i=b.size();i<a.size();i++)
    {
        res[i] = a[i];
    }
    for (int i=0;i<res.size();i++)
    {
        if (res[i]<0)
        {
            res[i+1]--;
            res[i] += base;
        }
    }
    for (int i=res.size()-1;i>0;i--)
    {
        if (res[i]==0)
        {
            res.pop_back();
        }
        else
        {
            break;
        }
    }
    return res;
}
*/


int main() {
    ios_base::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    vector<pair<ll,ll>> kek(n+m);
    vector<ll> num(n+m);
    for (int i=0;i<n;i++) num[i] = i;
    ll mx = 10000000000LL;
    for (int i=0;i<m;i++) num[n+i] = mx;
    set<pair<ll,ll>> suk;
    set<pair<pair<ll,ll>,ll>> ordx, ordy;
    ll lft = m;
    for (int i=0;i<n;i++)
    {
        cin >> kek[i].X >> kek[i].Y;
        num[i] = kek[i].X+kek[i].Y;
        ordx.insert({{kek[i].X,num[i]},i});
        ordy.insert({{kek[i].Y,num[i]},i});
        suk.insert({kek[i].X,kek[i].Y});
    }
    vector<pair<ll,ll>> ask(m);
    vector<ll> ans(m);
    for (int i=0;i<m;i++)
    {
        cin >> ask[i].X >> ask[i].Y;
        if (suk.count({ask[i].X,ask[i].Y}))
        {
            ans[i] = 0;
            lft--;
            continue;
        }
        if (ask[i].X==0 and ask[i].Y==0)
        {
            ans[i] = 0;
            lft--;
            continue;
        }
        ordx.insert({{ask[i].X, num[i+n]},i+n});
        ordy.insert({{ask[i].Y,num[i+n]},i+n});
    }
    ll curx = 0;
    ll cury = 0;
    //ll prvx = -1;
    //ll prvy = -1;
    while (lft>0)
    {
        ll bstx = (*ordx.begin()).X.X - curx;
        ll posx = (*ordx.begin()).Y;
        ll bsty = (*ordy.begin()).X.X - cury;
        ll posy = (*ordy.begin()).Y;
        if (bstx*(mx+1)+num[posx]<=bsty*(mx+1)+num[posy])
        {
            ll pos = (*ordx.begin()).Y;
            if (pos>=n and pos<n+m)
            {
                lft--;
                pos -= n;
                ordx.erase({{ask[pos].X,num[pos+n]},pos+n});
                ordy.erase({{ask[pos].Y,num[pos+n]},pos+n});
                if (ask[pos].X-curx!=ask[pos].Y-cury or ask[pos].X<=curx or ask[pos].Y<=cury)
                {
                    ans[pos] = 1;
                    continue;
                }
                else
                {
                    ans[pos] = 0;
                    continue;
                }
            }
            if (kek[pos].X-curx<kek[pos].Y-cury)
            {
                ordx.erase({{kek[pos].X,num[pos]},pos});
                continue;
            }
            /*if (kek[pos].X-curx==kek[pos].Y-cury and num[pos]<n)
            {
                ordx.erase({{kek[pos].X,num[pos]},pos});
                ordy.erase({{kek[pos].Y,num[pos]},pos});
                curx = kek[pos].X;
                cury = kek[pos].Y;
                ordx.insert({{kek[pos].X,num[pos]},pos});
                ordy.insert({{kek[pos].Y,num[pos]},pos});
                //prvx = kek[pos].X;
                //prvy = kek[pos].Y;
                continue;
            }*/
            if (kek[pos].X-curx==kek[pos].Y-cury)
            {
                ordx.erase({{kek[pos].X,num[pos]},pos});
                ordy.erase({{kek[pos].Y,num[pos]},pos});
                if (cury>=kek[pos].Y) continue;
                curx = kek[pos].X;
                cury = kek[pos].Y;
                continue;
            }
            /*if (prvx==kek[pos].X)
            {
                ordx.erase({{kek[pos].X,num[pos]},pos});
                ordy.erase({{kek[pos].Y,num[pos]},pos});
                if (curx>=kek[pos].X) continue;
                if (prvx-curx==prvy-cury)
                {
                    curx = prvx;
                    cury = prvy;
                    continue;
                }
                cury += (kek[pos].X-1-curx);
                curx = kek[pos].X;
                prvx = curx;
            }
            else*/
            {
                ordx.erase({{kek[pos].X,num[pos]},pos});
                ordy.erase({{kek[pos].Y,num[pos]},pos});;
                if (curx>=kek[pos].X) continue;
                cury += (kek[pos].X-1-curx);
                curx = kek[pos].X;
                //prvx = curx;
            }
        }
        else
        {
            ll pos = (*ordy.begin()).Y;
            if (pos>=n and pos<n+m)
            {
                lft--;
                pos -= n;
                ordx.erase({{ask[pos].X,num[pos+n]},pos+n});
                ordy.erase({{ask[pos].Y,num[pos+n]},pos+n});
                if (ask[pos].X-curx!=ask[pos].Y-cury or ask[pos].X<=curx or ask[pos].Y<=cury)
                {
                    ans[pos] = 1;
                    continue;
                }
                else
                {
                    ans[pos] = 0;
                    continue;
                }
            }
            if (kek[pos].Y-cury<kek[pos].X-curx)
            {
                ordy.erase({{kek[pos].Y,num[pos]},pos});
                continue;
            }
            /*if (kek[pos].X-curx==kek[pos].Y-cury and pos<n)
            {
                ordx.erase({{kek[pos].X,num[pos]},pos});
                ordy.erase({{kek[pos].Y,num[pos]},pos});

                continue;
            }*/
            if (kek[pos].Y-cury==kek[pos].X-curx)
            {
                ordx.erase({{kek[pos].X,num[pos]},pos});
                ordy.erase({{kek[pos].Y,num[pos]},pos});
                if (cury>=kek[pos].Y) continue;
                curx = kek[pos].X;
                cury = kek[pos].Y;
                continue;
            }
            /*if (prvy==kek[pos].Y)
            {
                ordx.erase({{kek[pos].X,num[pos]},pos});
                ordy.erase({{kek[pos].Y,num[pos]},pos});
                if (cury>=kek[pos].Y) continue;
                if (prvx-curx==prvy-cury)
                {
                    curx = prvx;
                    cury = prvy;
                    continue;
                }
                curx += (kek[pos].Y-1-cury);
                cury = kek[pos].Y;
                prvy = cury;
            }
            else*/
            {
                ordx.erase({{kek[pos].X,num[pos]},pos});
                ordy.erase({{kek[pos].Y,num[pos]},pos});
                if (cury>=kek[pos].Y) continue;
                curx += (kek[pos].Y-1-cury);
                cury = kek[pos].Y;
            }
        }
    }
    for (int i=0;i<m;i++)
    {
        if (ans[i]==0)
        {
            cout << "LOSE" << endl;
        }
        else
        {
            cout << "WIN" << endl;
        }
    }
}