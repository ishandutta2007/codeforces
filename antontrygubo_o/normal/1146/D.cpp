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

const int p = 998244353;


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


vector<bool> c;
int cnt = 1;
int bound = 0;

int a, b;

void dfs(int i)
{
    if (i>=b && c[i-b]==0)
    {
        c[i-b] = 1;
        cnt++;
        dfs(i-b);
    }
    if (i+a<=bound&&c[i+a]==0)
    {
        c[i+a] = 1;
        cnt++;
        dfs(i+a);
    }
}

ll sol(ll l, ll r, ll d)
{
    ll answer = 0;
    while (l<=r&&l%d!=0) {answer+=l/d+1; l++;}
    while (r>=l&&r%d!=d-1) {answer+=r/d+1; r--;}
    //cout<<"LOL "<<l<<' '<<r<<' '<<answer<<endl;
    if (l>r) return answer;
    l = l/d;
    r = r/d;
    answer+=d*( (r+1)*(r+2)/2  - l*(l+1)/2);
    return answer;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    ll m;
    cin>>m>>a>>b;
    ll gcd = __gcd(a, b);
    ll answer = 0;
    int sum = a+b;
    if (m>=sum)
    {
        //cout<<sum<<' '<<m<<' '<<gcd<<endl;
        //cout<<sol(sum, m, gcd)<<endl;
        answer+= sol(sum, m, gcd);
        m = sum-1;
    }

    c.resize(m+1);
    c[0] = 1;
    for (int i = 0; i<=m; i++)
    {
          bound = i;
          if (i<a||c[i-a]==0) {answer+=cnt; continue;}
          c[i]=1;
          cnt++;
          dfs(i);
          answer+=cnt;
    
        //cout<<i<<' '<<cnt<<endl;
    }
    cout<<answer;
    
}