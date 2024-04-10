#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
/*#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/

using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define ld long double
#define mp make_pair
 
typedef long double DOUBLE;
typedef complex<DOUBLE> COMPLEX;
typedef vector<DOUBLE> VD;
typedef vector<COMPLEX> VC;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

 
void print(auto &a)
{
    for (auto s: a) cout<<s<<' ';
    cout<<endl;
}
 
void get(vector<auto> &a)
{
    for (int i = 0; i<(int)a.size(); i++) cin>>a[i];
}
 
const int p = 998244353;
 
 
int mul(int a, int b) {
    return (1LL * a%p * b%p) % p;
}
 
int add(int a, int b) {
    int s = (a+b);
    s = s%p;
    if (s<0) s+=p; 
    return s;
}
 
int sub(int a, int b) {
    int s = (a-b);
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
 
vector<int> Z(vector<int> s)
{
int n = s.size();
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

mt19937 rnd(time(0));

int MAXX = 500000;

vector<vector<int>> ancestor(MAXX+1, vector<int>(20));

void solve(int x, int y)
{
    int cnt = 0;
    while (x<y)
    {
        //cout<<x<<' '<<y<<endl;
        int idx = 0;
        if (ancestor[x][0]==-1) {cout<<-1<<endl; return;}
        if (ancestor[x][0]>=y) {cout<<cnt+1<<endl; return;}
        while (idx<19&&ancestor[x][idx+1]!=-1) idx++;
        while (ancestor[x][idx]>=y) idx--;
        cnt+=(1<<idx);
        x = ancestor[x][idx];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);


    int n, m;
    cin>>n>>m;
    vector<pair<int, int>> a(n);
    for (int i = 0; i<n; i++) cin>>a[i].first>>a[i].second;
    
    sort(a.begin(), a.end());
    vector<int> link(MAXX+1);
    int idx = 0;
    int maxx = -1;
    for (int i = 0; i<=MAXX; i++)
    {
        while (idx<n&&a[idx].first<=i) {maxx = max(maxx, a[idx].second); idx++;}
        if (maxx<=i) link[i] = -1;
        else link[i] = maxx;
    }
    
    
    for (int i = MAXX; i>=0; i--)
    {
        ancestor[i][0] = link[i];
        for (int j = 1; j<20; j++)
        {
            if (ancestor[i][j-1]==-1) ancestor[i][j] = -1;
            else ancestor[i][j] = ancestor[ancestor[i][j-1]][j-1];
        }
    }
    
    /*for (int i = 0; i<30; i++) cout<<link[i]<<' ';
    cout<<endl;
    for (int i = 0; i<10; i++)
    {
        cout<<i<<": ";
        print(ancestor[i]);
    }*/
    
    for (int i = 0; i<m; i++)
    {
        int x, y;
        cin>>x>>y;
        solve(x, y);
    }

    

    
}