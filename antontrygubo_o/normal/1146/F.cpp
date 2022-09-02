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


vector<vector<int>> G;
vector<int> take;
vector<int> nottake;
vector<int> postake;

void dfs(int i)
{
    if (G[i].size()==0)
    {
        take[i] = 1;
        postake[i] = 1;
        nottake[i] = 0;
        return;
    }
    for (auto it: G[i]) dfs(it);
    nottake[i] = 1;
    for (auto it: G[i]) nottake[i] = mul(nottake[i], add(take[it], nottake[it]));
    postake[i] = 1;
    for (auto it: G[i]) postake[i] = mul(postake[i], add(postake[it], add(nottake[it], take[it])));
    postake[i] = add(postake[i], -nottake[i]);
    take[i] = postake[i];
    for (auto it: G[i]) take[i] = add(take[i], -mul(postake[it], mul(nottake[i], inv(add(take[it],nottake[it])))));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin>>n;
    G.resize(n+1);
    int x;
    for (int i = 2; i<=n; i++)
    {
        cin>>x;
        G[x].push_back(i);
    }
    take.resize(n+1);
    nottake.resize(n+1);
    postake.resize(n+1);
    dfs(1);
    cout<<add(take[1], nottake[1])<<endl;
    //for (int i = 1; i<=n; i++) cout<<i<<": "<<take[i]<<' '<<postake[i]<<' '<<nottake[i]<<endl;
    
}