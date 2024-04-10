#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

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

ll p = 1LL<<42;


ll mul(ll a, ll b) {
    return (1LL * a%p * b%p) % p;
}

ll add(ll a, ll b) {
    ll s = (a+b);
    s = s%p;
    if (s<0) s+=p; 
    return s;
}

ll po(ll a, ll deg)
{
    if (deg==0) return 1;
    if (deg%2==1) return mul(a, po(a, deg-1));
    ll t = po(a, deg/2);
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
    vector<int> a(n);
    get(a);
    vector<int> maxr(n);
    vector<int> maxl(n);
    maxr[n-1] = 1;
    for (int i = n-2; i>=0; i--)
    {
        if (a[i]>=a[i+1]) maxr[i] = 1;
        else maxr[i] = maxr[i+1]+1;
    }
    maxl[0] = 1;
    for (int i = 1; i<n; i++)
    {
        if (a[i]>=a[i-1]) maxl[i] = 1;
        else maxl[i] = maxl[i-1] + 1;
    }
    
    int l = 0;
    int r = n-1;
    int maxx = 0;
    int cur = 0;
    int prev = -1;
    //print(maxl);
    //print(maxr);
    while (r>=l)
    {
        if (a[r]>a[l])
        {
            if (a[r]>prev) maxx = max(maxx, cur+maxl[r]);
            if (a[l]<=prev) break;
            prev = a[l];
            l++;
            cur++;
        }
        else if (a[l]>=a[r])
        {
            if (a[l]>prev) maxx = max(maxx, cur+maxr[l]);
            if (a[r]<=prev) break;
            prev = a[r];
            r--;
            cur++;
        }
        //cout<<l<<' '<<r<<' '<<prev<<' '<<cur<<endl;
    }
    cout<<maxx<<endl;
    l = 0;
    r = n-1;
    cur = 0;
    prev = -1;
    string s;
    while (r>=l)
    {
        if (a[r]>a[l])
        {
            if (a[r]>prev) 
            {
                if (cur+maxl[r]==maxx)
                {
                    cout<<s;
                    for (int i = 0; i<maxl[r]; i++) cout<<'R';
                    return 0;
                }
            }
            if (a[l]<=prev) break;
            prev = a[l];
            l++;
            cur++;
            s+='L';
        }
        else if (a[l]>=a[r])
        {
            if (a[l]>prev) 
            {
                if (cur+maxr[l]==maxx)
                {
                    cout<<s;
                    for (int i = 0; i<maxr[l]; i++) cout<<'L';
                    return 0;
                }
            }
            if (a[r]<=prev) break;
            prev = a[r];
            r--;
            cur++;
            s+='R';
        }
        //cout<<l<<' '<<r<<' '<<prev<<' '<<cur<<endl;
    }
    cout<<s;
}