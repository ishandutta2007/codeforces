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
 /*
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
 */
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


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    ll d, m, n;
    cin>>d>>n>>m;
    vector<int> x(m+1);
    vector<int> cost(m);
    
    vector<pair<int, int>> fuck(m);
    
    for (int i = 0; i<m; i++) cin>>fuck[i].first>>fuck[i].second;
    sort(fuck.begin(), fuck.end());
    
    for (int i = 0; i<m; i++) {x[i] = fuck[i].first; cost[i] = fuck[i].second;}
    x[m] = d;    
    if (x[0]>n) {cout<<-1; return 0;}
    for (int i = 0; i<m; i++) if (x[i+1]-x[i]>n) {cout<<-1; return 0;}
    

    
    ll total = 0;
    ll cur = n-x[0];
    vector<int> nex(m);
    stack<int> lol;
    for (int i = m-1; i>=0; i--)
    {
        while (!lol.empty()&&cost[lol.top()]>cost[i]) lol.pop();
        if (lol.empty()) nex[i] = m;
        else nex[i] = lol.top();
        lol.push(i);
    }
    //print(nex);
    
    for (int i = 0; i<m; i++)
    {
        if (i>0) cur-=(x[i]-x[i-1]);
        //cout<<cur<<' '<<total<<endl;
        if (nex[i]==m)
        {
            ll spend = max((long long)0, min(n-cur, d-x[i]-cur));
            cur+=spend;
            total+=spend*cost[i];
            continue;
        }
        if (x[i]+n>=x[nex[i]])
        {
            ll spend = max((long long)0, x[nex[i]]-x[i]-cur);
            cur+=spend;
            total+=cost[i]*spend;
            continue;            
        }
        else
        {
            ll spend = n-cur;
            cur+=spend;
            total+=cost[i]*spend;
            continue;    
        }
    }
    
    cout<<total;

    
}