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

ll solve(vector<ll> a) 
{ 
    int n = a.size();
    // Arrays for maintaining left and right count 
    vector<ll> CL(n), CR(n);
    
  
    // Stack for storing the indexes 
    stack<int> q; 
  
    // Calculate left count for every index 
    for (int i = 0; i < n; i++) { 
        while (q.size() != 0 && a[q.top()] <= a[i]) { 
            CL[i] += CL[q.top()] + 1; 
            q.pop(); 
        } 
        q.push(i); 
    } 
  
    // Clear the stack 
    while (q.size() != 0) 
        q.pop(); 
  
    // Calculate right count for every index 
    for (int i = n - 1; i >= 0; i--) { 
        while (q.size() != 0 && a[q.top()] < a[i]) { 
            CR[i] += CR[q.top()] + 1; 
            q.pop(); 
        } 
        q.push(i); 
    } 
  
    // Clear the stack 
    while (q.size() != 0) 
        q.pop(); 
  
    // To store the required sum 
    ll ans = 0; 
  
    // Calculate the final sum 
    for (int i = 0; i < n; i++) 
        ans += (CL[i] + 1) * (CR[i] + 1) * a[i]; 
  
    return ans; 
} 


int main()
{
    int n, m;
    cin>>n>>m;
    if (m==1) {cout<<1; return 0;}
    vector<int> x(n);
    get(x);
    int N = 101010;
    vector<DOUBLE> dp(N+1);
    int total = 0;
    for (int i = 0; i<n; i++) total+=x[i];
    dp[0] = 1.0;
    for (int i = 0; i<n; i++)
    {
        int l = N-m;
        int r = N-1;
        DOUBLE cur = 0;
        for (int j = l; j<=r; j++) cur+=dp[j];
        dp[N] = cur - dp[N-x[i]];
        for (int k = N-1; k>=0; k--)
        {
            cur-=dp[r];
            r--;
            l--;
            if (l>=0) cur+=dp[l];
            dp[k] = cur;
            if (k>=x[i]) dp[k]-=dp[k-x[i]];
        }
        for (int k = 0; k<=N; k++) dp[k] = dp[k]/DOUBLE(m-1);
        /*cout<<"Iteration "<<i<<":"<<endl;
        for (int j = 0; j<20; j++) cout<<j<<": "<<dp[j]<<endl;*/
    }
    DOUBLE prob = 0;
    for (int i = 0; i<total; i++) prob+=dp[i];
    cout<<setprecision(15)<<DOUBLE(m-1)*prob + 1<<endl;
    /*cout<<total<<endl;
    for (int i = 0; i<20; i++) cout<<i<<": "<<dp[i]<<endl;*/
    
}