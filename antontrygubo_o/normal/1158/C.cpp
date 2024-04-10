#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
/*#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
 
using namespace std;
#define ll long long
#define ld long double
#define mp make_pair
 
typedef long double DOUBLE;
typedef complex<DOUBLE> COMPLEX;
typedef vector<DOUBLE> VD;
typedef vector<COMPLEX> VC;
 
void print(auto &a)
{
    for (auto s: a) cout<<s<<' ';
    cout<<endl;
}
 
void get(vector<auto> &a)
{
    for (int i = 0; i<a.size(); i++) cin>>a[i];
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




vector<int> nex(vector<int> a)
{
    stack<int> lol;
    int n = a.size();
    vector<int> answer(n);
    for (int i = n-1; i>=0; i--)
    {
        while (!lol.empty()&&a[lol.top()]<a[i]) lol.pop();
        if (lol.empty()) answer[i] = n;
        else answer[i] = lol.top();
        lol.push(i);
    }
    
    return answer;
    
}





void solve()
{
    //cout<<"CASE"<<endl;
    int n;
    cin>>n;
    vector<int> a(n);
    get(a);
    for (int i = 0; i<n; i++)
    {
        if (a[i]!=-1) a[i]--;
        else a[i] = i+1;
    }
    
    vector<int> dp(n);
    for (int i = n-1; i>=0; i--)
    {
        if (a[i]==n) dp[i] = 0;
        else dp[i] = dp[a[i]]+1;
    }
    vector<int> b(n);
    vector<vector<int>> G(n);
    for (int i = 0; i<n; i++) G[dp[i]].push_back(i);
    int cur = n;
    for (int i = 0; i<n; i++)
    for (auto it: G[i])
    {
        b[it] = cur;
        cur--;
    }
    auto check = nex(b);
    /*print(a);
    print(b);
    print(check);*/
    if (check!=a) {cout<<-1<<endl; return;}
    else print(b);
    
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    cin>>t;
    for (int i = 0; i<t; i++) solve();
    
    

}