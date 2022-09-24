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

ll n, b;

int check(vector<ll> &l, vector<ll> &r)
{
    for (int i=0;i<b;i++)
        if (l[i]!=r[i]) return 1;
    return 0;
}

vector<ll> ask(vector<ll> &l, vector<ll> &r)
{
    vector<ll> kek(b+1);
    for (int i=0;i<b;i++)
    {
        kek[i] += l[i]+r[i];
        if (kek[i]>=2)
        {
            kek[i] -= 2;
            kek[i+1]++;
        }
    }
    for (int i=0;i<b;i++)
    {
        kek[i] = kek[i+1];
    }
    kek.pop_back();
    return kek;
}

vector<ll> add1(vector<ll> &m)
{
    vector<ll> kek(b);
    kek[0] = 1;
    for (int i=0;i<b;i++)
    {
        kek[i] += m[i];
        if (kek[i]>=2)
        {
            kek[i] -= 2;
            kek[i+1]++;
        }
    }
    return kek;
}

void query(ll cur, vector<ll> &kek)
{
    cout << cur+1 << " ";
    for (int i=b-1;i>=0;i--)
        cout << kek[i];
    cout << endl;
}

int check2(vector<ll> &l, vector<ll> &r)
{
    for (int i=b-1;i>=0;i--)
    {
        if (l[i]>r[i]) return 1;
        if (r[i]>l[i]) return 0;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> b;
    vector<vector<ll>> L(n, vector<ll>(b)), R(n,vector<ll>(b,1));
    vector<ll> ok(n);
    ll cur = 0;
    ll nxt = 0;
    ll lft = n;
    vector<ll> asked;
    vector<vector<ll>> need;
    while (true)
    {
        string s;
        ll lul = 1;
        ll w = 0;
        if (check(L[cur],R[cur]))
        {
            w++;
            vector<ll> kek = ask(L[cur],R[cur]);
            query(cur,kek);
            cin >> s;
            if (s=="yes")
            {
                L[cur] = add1(kek);
                lul = 0;
            }
            else
            {
                R[cur] = kek;
                need.push_back({});
                need.back() = kek;
            }
        }
        else
        {
            w++;
            if (lft==1)
            {
                query(-1, L[cur]);
                break;
            }
        }
        if (lft==1)
        {
            continue;
        }
        //if (lul==0) continue;
        //if (w%2==0) continue;
        int p = check(L[cur],R[cur]);
        for (int i=0;i<1;i++)
        {
        int t = 0;
        while (true)
        {
            if (t>=n or lft==1) break;
            while (nxt==cur or ok[nxt]==1)
            {
                t++;
                nxt++;
                if (nxt==n) nxt = 0;
            }
            if (check2(R[nxt],R[cur])==0)
            {
                if (p==0)
                {
                    ok[nxt] = 1;
                    lft--;
                }
                t++;
                nxt++;
                if (nxt==n) nxt = 0;
                if (lft==1) break;
                else continue;
            }
            break;
        }
        if (lft==1 or t>=n) continue;
        query(nxt,R[cur]);
        cin >> s;
        if (s=="no")
        {
            if (p==0)
            {
                ok[nxt] = 1;
                lft--;
            }
            asked.push_back(nxt);
            R[nxt] = R[cur];
            nxt++;
            if (nxt==n) nxt = 0;
            continue;
        }
        else
        {
            vector<ll> kek = add1(R[cur]);
            L[nxt] = kek;
            ok[cur] = 1;
            lft--;
            cur = nxt;
            /*while (need.size()>0)
            {
                vector<ll> keks = need.back();
                if (check2(L[cur],keks))
                {
                    need.pop_back();
                    continue;
                }
                if (check2(R[cur],keks)==0)
                {
                    need.pop_back();
                    continue;
                }
                query(cur,keks);
                cin >> s;
                if (s=="yes")
                {
                    L[cur] = add1(keks);
                    need.pop_back();
                    continue;
                }
                else
                {
                    R[cur] = keks;
                    need.pop_back();
                    continue;
                }
            }
            need.clear();*/
            while (asked.size()>0)
            {
                ll pos = asked.back();
                if (pos==cur)
                {
                    asked.pop_back();
                    continue;
                }
                if (ok[pos]==1)
                {
                    asked.pop_back();
                    continue;
                }
                if (check2(L[cur],R[pos]))
                {
                    ok[pos] = 1;
                    lft--;
                    asked.pop_back();
                    continue;
                }
                if (check2(R[cur],R[pos])==0)
                {
                    break;
                }
                query(cur,R[pos]);
                cin >> s;
                if (s=="yes")
                {
                    ok[pos] = 1;
                    lft--;
                    L[cur] = add1(R[pos]);
                    asked.pop_back();
                    continue;
                }
                else
                {
                    R[cur] = R[pos];
                    break;
                }
            }
            break;
        }
        }
    }
}