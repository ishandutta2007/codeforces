#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define mp make_pair

void print(auto &a)
{
    for (auto s: a) cout<<s<<' ';
    cout<<endl;
}

void get(vector<auto> &a)
{
    for (int i = 0; i<a.size(); i++) cin>>a[i];
}

const int p = 1e9 + 7;


int mul(int a, int b) {
    return (1LL * a%p * b%p) % p;
}

int add(int a, int b) {
    ll s = (a+b);
    s = s%p;
    if (s<0) s+=p; 
    return s;
}

int po(int a, int deg)
{
    if (deg==0) return 1;
    if (deg%2==1) return mul(a, po(a, deg-1));
    int t = po(a, deg/2);
    return mul(t, t);
}

int inv(int n)
{
    return po(n, p-2);
}



vector<int> Z(string s)
{
int n = s.length();
vector<int> z(n);
int L = 0, R = 0;
for (int i = 1; i < n; i++) {
  if (i > R) {
    L = R = i;
    while (R < n && s[R-L] == s[R]) R++;
    z[i] = R-L; R--;
  } else {
    int k = i-L;
    if (z[k] < R-i+1) z[i] = z[k];
    else {
      L = i;
      while (R < n && s[R-L] == s[R]) R++;
      z[i] = R-L; R--;
    }
  }
}
return z;
}


vector<int> t(1000000);

void build (vector<int> &a, int v, int tl, int tr) {
if (tl == tr)
t[v] = a[tl];
else {
int tm = (tl + tr) / 2;
build (a, v*2, tl, tm);
build (a, v*2+1, tm+1, tr);
t[v] = min(t[v*2], t[v*2+1]);
}
}

const int INF = 1e9;

int minn (int v, int tl, int tr, int l, int r) {
if (l > r)
return INF;
if (l == tl && r == tr)
return t[v];
int tm = (tl + tr) / 2;
return min(minn(v*2, tl, tm, l, min(r,tm))
, minn(v*2+1, tm+1, tr, max(l,tm+1), r));
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, m, q;
    cin>>n>>m>>q;
    vector<int> p(n);
    get(p);
    for (int i = 0; i<n; i++) p[i]--;
    vector<int> a(m);
    get(a);
    for (int i = 0; i<m; i++) a[i]--;
    vector<int> next(n);
    for (int i = 0; i<n; i++) next[p[i]] = p[(i+1)%n];

    vector<int> pre(n);
    for (int i = 0; i<n; i++) pre[p[i]] = p[(i+n-1)%n];

    vector<int> following(m);
    vector<int> lastmet(n);
    for (int i = 0; i<n; i++) lastmet[i] = -1;
    for (int i = m-1; i>=0; i--)
    {
        lastmet[a[i]] = i;
        following[i] = lastmet[next[a[i]]];
    }
    
    vector<int> preceding(m);
    vector<int> firstmet(n);
    for (int i = 0; i<n; i++) firstmet[i] = -1;
    for (int i = 0; i<m; i++)
    {
        firstmet[a[i]] = i;
        preceding[i] = firstmet[pre[a[i]]];
    }
    
    //print(p);
    //print(a);
    //cout<<endl;

    
    vector<vector<int>> precede(m);
    for (int i = 0; i<m; i++) if (following[i]!=-1) precede[following[i]].push_back(i); 
    
    vector<vector<int>> ancestor(m, vector<int>(20, -1));
    
    for (int i = m-1; i>=0; i--)
    {
        ancestor[i][0] = following[i];
        for (int j = 1; j<20&&ancestor[i][j-1]!=-1; j++)
        {
            ancestor[i][j] = ancestor[ancestor[i][j-1]][j-1];
        }
    }
    
    vector<int> degs;
    int cur = 0;
    int n1 = n-1;
    while (n1)
    {
        if (n1%2==1) degs.push_back(cur);
        cur++;
        n1/=2;
    }
    
    
    vector<int> permutanc(m);
    for (int i = m-1; i>=0; i--)
    {
        int curidx = i;
        for (int j = 0; j<degs.size()&&curidx!=-1; j++) curidx = ancestor[curidx][degs[j]];
        permutanc[i] = curidx;
    }

    for (int i = 0; i<m; i++) if (permutanc[i]==-1) permutanc[i] = INF;
    
    //print(permutanc);
    build(permutanc, 1, 0, m-1);
    for (int i = 0; i<q; i++)
    {
        int l, r;
        cin>>l>>r;
        l--;
        r--;
        int M = minn(1, 0, m-1, l, r);
        if (M<=r) cout<<1;
        else cout<<0;

    }
    
    

    
}