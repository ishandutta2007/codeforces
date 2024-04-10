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

const int p =  1e9 + 7;


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


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<vector<int>> G(n+1);
    int a, b;
    for (int i = 0; i<n-1; i++)
    {
        cin>>a>>b; G[a].push_back(b);
    }
    vector<int> color(n+1);
    for (int i = 1; i<=n; i++) cin>>color[i];
    vector<pair<int, int>> ans;
    for (int i = 1; i<=n; i++)
    {
        for (auto s: G[i]) if (color[i]!=color[s]) ans.push_back(mp(i, s));
    }
    
    if (ans.size()==0) {cout<<"YES"<<endl<<1; return 0;}
    bool check1 = 1;
    int s1 = ans[0].first;
    for (auto it: ans) if (s1!=it.first&&s1!=it.second) check1 = false;
    if (check1) {cout<<"YES"<<endl<<s1; return 0;}

    bool check2 = 1;
    int s2 = ans[0].second;
    for (auto it: ans) if (s2!=it.first&&s2!=it.second) check2 = false;
    if (check2) {cout<<"YES"<<endl<<s2; return 0;}
    
    cout<<"NO";
}