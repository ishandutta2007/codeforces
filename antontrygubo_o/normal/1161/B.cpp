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


 
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int n, m;
    cin>>n>>m;
    
    
    vector<vector<int>> start(n+1);
    int a, b;
    for (int i = 0; i<m; i++)
    {
        cin>>a>>b;
        if (a>b) swap(a, b);
        int k = b-a;
        if (2*k<n) start[k].push_back(a);
        if (2*k>n) start[n-k].push_back(b);
        if (2*k==n) {start[k].push_back(a); start[k].push_back(b);}
    }
    
    int total = 1;
    
    for (int i = 1; i<n; i++) if (start[i].size()>0)
    {
        sort(start[i].begin(), start[i].end());
        if (start[i].size()==1) {cout<<"No"; return 0;}
        //cout<<i<<": "; print(start[i]);
        vector<int> d;
        for (int j = 0; j<start[i].size()-1; j++) d.push_back(start[i][j+1]-start[i][j]);
        d.push_back(start[i][0]+n-start[i][start[i].size()-1]);
        //print(d);
        auto ans = Z(d);
        //print(ans);
        bool check = false;
        for (int j = 1; j<ans.size(); j++) if (ans.size()%j==0&&ans[j]==ans.size()-j)
        {
            check = true;
            int sum = 0;
            for (int t = 0; t<j; t++) sum+=d[t];
            total = total*(sum/__gcd(total, sum));
            break;
        }
        if (!check) {cout<<"No"; return 0;}
    }
    
    if (total==n) cout<<"No";
    else cout<<"Yes";
    
}