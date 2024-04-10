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

int p = 1e9 + 7;


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
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i<n; i++) get(a[i]);
    vector<int> row(n);
    vector<int> col(m);
    vector<vector<int>> cntrow(n, vector<int>(m));
    vector<vector<int>> cntcol(n, vector<int>(m));
    for (int i = 0; i<n; i++)
    {
        set<int> kek;
        for (int j = 0; j<m; j++) kek.insert(a[i][j]);
        vector<int> temp;
        for (auto it: kek) temp.push_back(it);
        row[i] = kek.size();
        for (int j = 0; j<m; j++) cntrow[i][j] = lower_bound(temp.begin(), temp.end(), a[i][j]) - temp.begin() + 1;
    }
    
    for (int j = 0; j<m; j++)
    {
        set<int> kek;
        for (int i = 0; i<n; i++) kek.insert(a[i][j]);
        vector<int> temp;
        for (auto it: kek) temp.push_back(it);
        col[j] = kek.size();
        for (int i = 0; i<n; i++) cntcol[i][j] = lower_bound(temp.begin(), temp.end(), a[i][j]) - temp.begin() + 1;
    }

    vector<vector<int>> answer(n, vector<int>(m));
    for (int i = 0; i<n; i++)
    for (int j = 0; j<m; j++)
    {
        answer[i][j] = max(cntcol[i][j], cntrow[i][j]) + max(row[i] - cntrow[i][j], col[j] - cntcol[i][j]);
    }
    for (int i = 0; i<n; i++) print(answer[i]);


}