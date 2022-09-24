#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = double;
#define X first
#define Y second

const ll mod = 1000000007;

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

inline ll mul(ll a, ll b)
{
    if (a*b<mod) return a*b;
    return a*b%mod;
}

inline ll pew(ll a, ll b)
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



/*const int MOD = 998244353;
const int root = 31;
const int root_1 = 128805723;
const int root_pw = 1<<23;
const int root = 31;
const int MOD = 469762049;
const int root_1 = 15658735;
const int root_pw = 1<<26;*/


/*void fft (vector<int> & a, bool invert) {
    int n = (int) a.size();

    for (int i=1, j=0; i<n; ++i) {
        int bit = n >> 1;
        for (; j>=bit; bit>>=1)
            j -= bit;
        j += bit;
        if (i < j)
            swap (a[i], a[j]);
    }

    for (int len=2; len<=n; len<<=1) {
        int wlen = invert ? root_1 : root;
        for (int i=len; i<root_pw; i<<=1)
            wlen = int (wlen * 1ll * wlen % mod);
        for (int i=0; i<n; i+=len) {
            int w = 1;
            for (int j=0; j<len/2; ++j) {
                int u = a[i+j],  v = int (a[i+j+len/2] * 1ll * w % mod);
                a[i+j] = u+v < mod ? u+v : u+v-mod;
                a[i+j+len/2] = u-v >= 0 ? u-v : u-v+mod;
                w = int (w * 1ll * wlen % mod);
            }
        }
    }
    if (invert) {
        int nrev = pew(n, mod-2);
        for (int i=0; i<n; ++i)
            a[i] = int (a[i] * 1ll * nrev % mod);
    }
}*/


int parent[600001];
int rnk[600001];

void make_set (int v) {
    parent[v] = v;
    rnk[v] = 0;
}

int find_set (int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets (int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rnk[a] < rnk[b])
            swap(a, b);
        parent[b] = a;
        if (rnk[a] == rnk[b])
            ++rnk[a];
    }
}

//ll t[1200000];
//ll del[1200000];

/*void build()
{
    for (int i=0;i<1200000;i++)
    {
        t[i] = 0;
        //del[i] = 0;
    }
}*/

/*void push(int v, int tl, int tr, int tm)
{
    t[2*v].X += del[v];
    t[2*v+1].X += del[v];
    del[2*v] += del[v];
    del[2*v+1] += del[v];
    del[v] = 0;
}*/

/*void update (int v, int tl, int tr, int l, int r, ll val) {
    if (tl==l and tr==r)
    {
        //del[v] += val;

        //t[v] += val*(tr-tl+1);
        return;
    }
    int tm = (tl + tr) / 2;
    //if (del[v]!=0) push(v,tl,tr,tm);
    if (r<=tm)
    {
        update(2*v,tl,tm,l,r,val);
        t[v] = t[2*v]+t[2*v+1];
        return;
    }
    if (l>tm)
    {
        update(2*v+1,tm+1,tr,l,r,val);
        t[v] = t[2*v]+t[2*v+1];
        return;
    }
    update(2*v,tl,tm,l,tm,val);
    update(2*v+1,tm+1,tr,tm+1,r,val);
    t[v] = min(t[2*v],t[2*v+1]);
}*/


/*void update (int v, int tl, int tr, int pos, ll val) {
    if (tl==tr)
    {
        //del[v] += val;
        t[v] += val;
        return;
    }
    int tm = (tl+tr)/2;
    //push(v,tl,tr,tm);
    if (pos<=tm)
    {
        update(2*v,tl,tm,pos,val);
        t[v] = t[2*v]+t[2*v+1];
        return;
    }
    else
    {
        update(2*v+1,tm+1,tr,pos,val);
        t[v] = t[2*v]+t[2*v+1];
        return;
    }
    //update(2*v,tl,tm,l,tm,val);
    //update(2*v+1,tm+1,tr,tm+1,r,val);
    //t[v] = min(t[2*v],t[2*v+1]);
}



ll get (int v, int tl, int tr, int l, int r) {
    //if (del[v]!=0 and tl!=tr) push(v,tl,tr,tm);
    if (tl==l and tr==r)
    {
        return t[v];
    }
    int tm = (tl+tr)/2;
    //push(v,tl,tr,tm);
    if (r<=tm) return get(2*v,tl,tm,l,r);
    if (l>tm) return get(2*v+1,tm+1,tr,l,r);
    return get(2*v,tl,tm,l,tm)+get(2*v+1,tm+1,tr,tm+1,r);
}*/



int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<string> cur(n);
    int k = 0;
    vector<int> c(n), a(n);
    for (int i=0;i<n;i++)
    {
        cin >> cur[i] >> c[i];
        for (int j=0;j<cur[i].length();j++)
        {
            if (cur[i][j]<'0' or cur[i][j]>'9') a[i] = -1;
        }
        if (cur[i][0]=='0') a[i] = -1;
        if (c[i]==1) k++;
        if (a[i]!=-1)
        {
            for (int j=0;j<cur[i].length();j++)
            {
                a[i] = a[i]*10+(cur[i][j]-'0');
            }
        }
        if (a[i]>n) a[i] = -1;
    }
    vector<int> was(n+1);
    int ok = 0;
    set<int> L1, L2, R1, R2;
    for (int i=0;i<n;i++)
    {
        if (a[i]==-1)
        {
            if (c[i]==1)
            {
                L2.insert(i);
            }
            else
            {
                R2.insert(i);
            }
            continue;
        }
        if (c[i]==1)
        {
            if (a[i]<=k)
            {
                was[a[i]] = 1;
                ok++;
                continue;
            }
            was[a[i]] = 1;
            L1.insert(i);
        } else
        {
            if (a[i]>k)
            {
                was[a[i]] = 1;
                ok++;
                continue;
            }
            was[a[i]] = 1;
            R1.insert(i);
        }
    }
    vector<int> q;
    for (int i=1;i<=n;i++)
    {
        if (was[i]==0) q.push_back(i);
    }
    vector<string> ans, ans2;
    for (int p=0;p<q.size();p++)
    {
        int u = q[p];
        string s = to_string(u);
        ok++;
        if (u<=k)
        {
            if (L1.size()>0)
            {
                int v = *L1.begin();
                L1.erase(v);
                ans.push_back(cur[v]);
                ans2.push_back(s);
                q.push_back(a[v]);
                continue;
            }
            int v = *L2.begin();
            L2.erase(v);
            ans.push_back(cur[v]);
            ans2.push_back(s);
            continue;
        } else
        {
            if (R1.size()>0)
            {
                int v = *R1.begin();
                R1.erase(v);
                ans.push_back(cur[v]);
                ans2.push_back(s);
                q.push_back(a[v]);
                continue;
            }
            int v = *R2.begin();
            R2.erase(v);
            ans.push_back(cur[v]);
            ans2.push_back(s);
            continue;
        }
    }

    while (ok<n) {
        q.clear();
        int V = *L1.begin();
        L1.erase(V);
        L2.insert(V);
        q.push_back(a[V]);
        ans.push_back(cur[V]);
        ans2.push_back(to_string(n+1));
        cur[V] = to_string(n+1);
        for (int p=0;p<q.size();p++)
        {
            int u = q[p];
            string s = to_string(u);
            ok++;
            if (u<=k)
            {
                if (L1.size()>0)
                {
                    int v = *L1.begin();
                    L1.erase(v);
                    ans.push_back(cur[v]);
                    ans2.push_back(s);
                    q.push_back(a[v]);
                    continue;
                }
                int v = *L2.begin();
                L2.erase(v);
                ans.push_back(cur[v]);
                ans2.push_back(s);
                continue;
            } else
            {
                if (R1.size()>0)
                {
                    int v = *R1.begin();
                    R1.erase(v);
                    ans.push_back(cur[v]);
                    ans2.push_back(s);
                    q.push_back(a[v]);
                    continue;
                }
                int v = *R2.begin();
                R2.erase(v);
                ans.push_back(cur[v]);
                ans2.push_back(s);
                continue;
            }
        }
    }
    int A = ans.size();
    cout << A << endl;
    for (int i=0;i<A;i++)
    {
        cout << "move " << ans[i] << " " << ans2[i] << endl;
    }

}