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

    ll n, x;
    cin>>n>>x;
    vector<int> a(n);
    get(a);
    for (int i = 0; i<n; i++) a[i]--;
    vector<vector<int>> pos(x);
    for (int i = 0; i<n; i++) pos[a[i]].push_back(i);
    vector<int> minn(x);
    vector<int> maxx(x);
    for (int i = 0; i<x; i++)
    {
        if (pos[i].size()==0) {minn[i] = -1; maxx[i] = -1; continue;}
        minn[i] = pos[i][0];
        maxx[i] = pos[i][0];
        for (auto it: pos[i]) 
        {
            minn[i] = min(minn[i], it);
            maxx[i] = max(maxx[i], it);
        }
    }
    
    vector<int> from_start;
    int cur_max = -1;
    from_start.push_back(-1);
    for (int i = 0; i<x; i++)
    {
        if (minn[i]==-1)
        {
            from_start.push_back(cur_max);
            continue;
        }
        if (minn[i]>cur_max)
        {
            cur_max = maxx[i];
            from_start.push_back(cur_max);
        }
        else break;
    }
    
    vector<int> from_end;
    int cur_min = n;
    from_end.push_back(n);
    for (int i = x-1; i>=0; i--)
    {
        if (maxx[i]==-1)
        {
            from_end.push_back(cur_min);
            continue;
        }
        if (maxx[i]<cur_min)
        {
            cur_min = minn[i];
            from_end.push_back(minn[i]);
        }
        else break;
    }
    ll total = 0;
    int pos_end = from_end.size()-1;
    
    //print(from_start);
    //print(from_end);
    
    if (from_start.size()==x+1)
    {
        cout<<x*(x+1)/2;
        return 0;
    }
    
    for (int i = 0; i<from_start.size(); i++)
    {
        while (from_end[pos_end]<from_start[i]) pos_end--;
        while (i+pos_end>x) pos_end--;
        total+=(pos_end+1);
    }
    cout<<total;

}