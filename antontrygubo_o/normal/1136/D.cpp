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

const int p =  998244353;


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
    
    int n, m;
    cin>>n>>m;
    vector<int> p(n+1);
    for (int i = 1; i<=n; i++) cin>>p[i];
    vector<vector<int>> G(n+1);
    for (int i = 0; i<m; i++)
    {
        int a, b;
        cin>>a>>b;
        G[a].push_back(b);
    }
    
    vector<bool> visited(n+1);
    
    vector<int> pos(n+1);
    for (int i = 1; i<=n; i++) pos[p[i]] = i;
    
    int counter = 1;
    
    for (int i = n-1; i>=1; i--)
    {
        int cnt = 0;
        for (auto it: G[p[i]]) if (pos[it]>i&&!visited[it]) cnt++;
        if (cnt==counter) {visited[p[i]] = 1; counter--;}
        counter++;
    }
    
    int total = 0;
    for (int i = 1; i<=n; i++) total+=visited[i];
    cout<<total;

}