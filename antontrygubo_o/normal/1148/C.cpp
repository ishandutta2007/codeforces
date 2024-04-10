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
 /*
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

vector<pair<int, int>> op;
vector<int> p;
vector<int> pos;

void sw(int i, int j)
{
    op.push_back(mp(i, j));
    swap(p[i], p[j]);
    swap(pos[p[i]], pos[p[j]]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int n;
    cin>>n;
    p.resize(n+1);
    pos.resize(n+1);
    for (int i = 1; i<=n; i++) cin>>p[i];

    for (int i = 0; i<=n; i++) pos[p[i]] = i;
    for (int i = 2; i<n; i++)
    {
        if (abs(pos[i]-i)>=n/2)
        {
            sw(pos[i], i);
        }
        else if (abs(pos[i]-i)<n/2)
        {
            if (pos[i]!=1&&pos[i]!=n)
            {
                if (pos[i]<=n/2) 
                {
                    sw(pos[i], n);                   
                }
                else sw(pos[i], 1);
            }
            if (abs(pos[i]-i)<n/2) sw(1, n);
            sw(pos[i], i);
        }
    }
    if (pos[1]!=1) sw(1, n);
    cout<<op.size()<<endl;
    for (auto it: op) cout<<it.first<<' '<<it.second<<endl;
}