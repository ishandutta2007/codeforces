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

void solve()
{
    int n, m;
    cin>>n>>m;
    vector<vector<char>> a(n, vector<char>(m));
    for (int i = 0; i<n; i++)
    for (int j = 0; j<m; j++) cin>>a[i][j];
    char maxx = '.';
    for (int i = 0; i<n; i++)
    for (int j = 0; j<m; j++) maxx = max(maxx, a[i][j]);
    if (maxx=='.') {cout<<"YES"<<endl<<0<<endl; return;}
    int N = maxx-'a';
    vector<vector<pair<int, int>>> cols(26);
    for (int i = 0; i<n; i++)
    for (int j = 0; j<m; j++) if (a[i][j]!='.') cols[a[i][j]-'a'].push_back(mp(i, j));
    vector<pair<int, int>> star;
    
    vector<pair<pair<int, int>, pair<int, int>>> answer;
    for (int M = N; M>=0; M--)
    {
        if (cols[M].size()==0)
        {
            if (star.size()==0) {cout<<"NO"<<endl; return;}
            else
            {
                answer.push_back(mp(star[0], star[0]));
            }
            continue;
        }
        if (cols[M].size()==1)
        {
            answer.push_back(mp(cols[M][0], cols[M][0])); a[cols[M][0].first][cols[M][0].second] = '*'; star.push_back(cols[M][0]); continue;
        }
        int max_x = -1;
        int max_y = -1;
        int min_x = 1000000;
        int min_y = 1000000;
        for (auto it: cols[M])
        {
            max_x = max(max_x, it.second);
            min_x = min(min_x, it.second);
            max_y = max(max_y, it.first);
            min_y = min(min_y, it.first);
        }
        //cout<<max_x<<' '<<max_y<<' '<<min_x<<' '<<min_y<<endl;
        if (max_x!=min_x&&max_y!=min_y) {cout<<"NO"<<endl; return;}
        if (max_x==min_x)
        {
            bool check = true;
            for (int i = min_y; i<=max_y; i++) if (a[i][min_x]!='a'+M&&a[i][min_x]!='*') check = false;
            if (check)
            {
                answer.push_back(mp(mp(min_y, min_x), mp(max_y, max_x)));
                for (int i = min_y; i<=max_y; i++) {a[i][min_x] = '*'; star.push_back(mp(i, min_x)); }               
            }
            else {cout<<"NO"<<endl; return;}
        }
        if (max_y==min_y)
        {
            bool check = true;
            for (int i = min_x; i<=max_x; i++) if (a[min_y][i]!='a'+M&&a[max_y][i]!='*') check = false;
            if (check)
            {
                answer.push_back(mp(mp(min_y, min_x), mp(max_y, max_x)));
                for (int i = min_x; i<=max_x; i++) {a[min_y][i] = '*'; star.push_back(mp(min_y, i));  }             
            }
            else {cout<<"NO"<<endl; return;}
        }
    }
    cout<<"YES"<<endl<<N+1<<endl;
    for (int i = N; i>=0; i--) cout<<answer[i].first.first+1<<' '<<answer[i].first.second+1<<' '<<answer[i].second.first+1<<' '<<answer[i].second.second+1<<endl;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);  
    
    int t;
    cin>>t;
    for (int i = 0; i<t; i++) solve();
    
    
}