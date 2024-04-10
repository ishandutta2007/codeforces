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

const int p = 1e9 + 7;
 
 
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
 
mt19937 rnd(time(0));

const int MAXX = 1e9;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin>>n;
    vector<pair<bool, pair<int, int>>> a(n);
    int R, B;
    R = 0;
    B = 0;
    int r, b;
    for (int i = 0; i<n; i++)
    {
        char c;
        cin>>c;
        if (c=='R') a[i].first = 0;
        else a[i].first = 1;
        cin>>r>>b;
        if (r>=16) {R+=(r-15); r = 15;}
        if (b>=16) {B+=(b-15); b = 15;}
        a[i].second = mp(r, b);
    }
    
    vector<vector<int>> answer(1<<n, vector<int>(256));
    for (int mask = 1; mask<(1<<n); mask++)
    {
        for (int i = 0; i<256; i++) answer[mask][i] = MAXX;
        int cntr = 0;
        int cntb = 0;
        for (int i = 0; i<n; i++) if (mask&(1<<i))
        {
            if (a[i].first) cntb++;
            else cntr++;
        }
        
        //cout<<cntr<<' '<<cntb<<endl;
        
        for (int i = 0; i<n; i++) if (mask&(1<<i))
        {
            int cntr1 = cntr;
            int cntb1 = cntb;
            if (a[i].first) cntb1--;
            else cntr1--;
            cntr1 = max(0, a[i].second.first - cntr1);
            cntb1 = max(0, a[i].second.second - cntb1);
            for (int j = 0; j<256; j++)
            {
                if (j>=cntr1) answer[mask][j] = min(answer[mask][j], cntb1 + answer[mask^(1<<i)][j-cntr1]);
            }
        }
    }
    int minn = MAXX;

    //for (int i = 0; i<(1<<n); i++) {cout<<i<<": "; print(answer[i]);}

    for (int i = 0; i<256; i++) minn = min(minn, max(R+i, B + answer[(1<<n)-1][i]));
    cout<<minn+n;
    
    
    
}