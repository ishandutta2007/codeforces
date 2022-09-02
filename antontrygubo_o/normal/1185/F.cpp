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
 
/*const int p = 1e9 + 9;
 
 
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
}*/
 
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


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);  
    
    int n, m;
    cin>>n>>m;
    vector<int> a(512);
    for (int i = 0; i<n; i++)
    {
        int t;
        cin>>t;
        int cur = 0;
        int r;
        for (int j = 0; j<t; j++)
        {
            cin>>r; cur+=(1<<(r-1));
        }
        a[cur]++;
    }
    vector<int> sums(512);
    for (int i = 0; i<512; i++)
    for (int j = 0; j<512; j++) if ((i&j)==j) sums[i]+=a[j];
    vector<vector<pair<int, int>>> prices(512);
    for (int i = 0; i<m; i++)
    {
        int price, t, r;
        cin>>price>>t;
        int cur = 0;
        for (int j = 0; j<t; j++)
        {
            cin>>r; cur+=(1<<(r-1));
        }
        prices[cur].push_back(mp(price, i+1));
    }
    for (int i = 0; i<512; i++) sort(prices[i].begin(), prices[i].end());
    auto ans = mp(-1, -1);
    int cnt = -1;
    int minn = 1000000000;
    for (int i = 0; i<512; i++)
    for (int j = i+1; j<512; j++) if (prices[i].size()>0&&prices[j].size()>0)
    {
        if (sums[i|j]>=cnt)
        {
            if (sums[i|j]>cnt) {cnt = sums[i|j]; ans = mp(prices[i][0].second, prices[j][0].second); minn = prices[i][0].first + prices[j][0].first;}
            else if (sums[i|j]==cnt) 
            {
                if (minn > prices[i][0].first + prices[j][0].first) {cnt = sums[i|j]; ans = mp(prices[i][0].second, prices[j][0].second); minn = prices[i][0].first + prices[j][0].first;}
            }
        }
    }
    
    for (int i = 0; i<512; i++) if (prices[i].size()>=2&&sums[i]>=cnt)
    {
        if (sums[i]>=cnt)
        {
            if (sums[i]>cnt) {cnt = sums[i]; ans = mp(prices[i][0].second, prices[i][1].second); minn = prices[i][0].first + prices[i][1].first;}
            else if (minn > prices[i][0].first + prices[i][1].first) {cnt = sums[i]; ans = mp(prices[i][0].second, prices[i][1].second); minn = prices[i][0].first + prices[i][1].first;}
        }
    }
    cout<<ans.first<<' '<<ans.second;
    
}