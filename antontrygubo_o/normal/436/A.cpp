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


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, x;
    cin>>n>>x;
    vector<pair<int, int>> candy0;
    vector<pair<int, int>> candy1;
    for (int i = 0; i<n; i++)
    {
        int t, h, m;
        cin>>t>>h>>m;
        if (t==0) candy0.push_back(mp(h, m));
        else candy1.push_back(mp(h, m));
    }
    int N0 = candy0.size();
    int N1 = candy1.size();
    vector<bool> taken0(N0);
    vector<bool> taken1(N1);
    int max1 = 0;
    int curx = x;
    bool curtake = 0;
    while (true)
    {
        if (curtake)
        {
            int maxx = -1;
            for (int i = 0; i<N1; i++) if (!taken1[i]&&candy1[i].first<=curx) maxx = max(maxx, candy1[i].second);
            if (maxx==-1) break;
            for (int i = 0; i<N1; i++) if (!taken1[i]&&candy1[i].first<=curx&&candy1[i].second == maxx) {taken1[i] = true; curx+=maxx; break;}   
            max1++;
        }
        else 
        {
            int maxx = -1;
            for (int i = 0; i<N0; i++) if (!taken0[i]&&candy0[i].first<=curx) maxx = max(maxx, candy0[i].second);
            if (maxx==-1) break;
            for (int i = 0; i<N0; i++) if (!taken0[i]&&candy0[i].first<=curx&&candy0[i].second == maxx) {taken0[i] = true; curx+=maxx; break;}    
            max1++;
        }     
        curtake = !curtake;
    }
    taken0 = vector<bool>(N0);
    taken1 = vector<bool>(N1);
    curtake = 1;
    curx = x;
    int max2 = 0;
    while (true)
    {
        if (curtake)
        {
            int maxx = -1;
            for (int i = 0; i<N1; i++) if (!taken1[i]&&candy1[i].first<=curx) maxx = max(maxx, candy1[i].second);
            if (maxx==-1) break;
            for (int i = 0; i<N1; i++) if (!taken1[i]&&candy1[i].first<=curx&&candy1[i].second == maxx) {taken1[i] = true; curx+=maxx; break;}   
            max2++;
        }
        else 
        {
            int maxx = -1;
            for (int i = 0; i<N0; i++) if (!taken0[i]&&candy0[i].first<=curx) maxx = max(maxx, candy0[i].second);
            if (maxx==-1) break;
            for (int i = 0; i<N0; i++) if (!taken0[i]&&candy0[i].first<=curx&&candy0[i].second == maxx) {taken0[i] = true; curx+=maxx; break;}    
            max2++;
        }     
        curtake = !curtake;
    }
    cout<<max(max1, max2);

}