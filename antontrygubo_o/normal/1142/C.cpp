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

const int p = 1e9 + 7;


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


struct pt {
ll x, y;
};
bool cmp (pt a, pt b) {
return a.x < b.x || a.x == b.x && a.y < b.y;
}
bool cw (pt a, pt b, pt c) {
return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}
bool ccw (pt a, pt b, pt c) {
return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}
void convex_hull (vector<pt> & a) {
if (a.size() == 1) return;
sort (a.begin(), a.end(), &cmp);
pt p1 = a[0], p2 = a.back();
vector<pt> up, down;
up.push_back (p1);
down.push_back (p1);
for (size_t i=1; i<a.size(); ++i) {
if (i==a.size()-1 || cw (p1, a[i], p2)) {
while (up.size()>=2 && !cw (up[up.size()-2], up[up.
size()-1], a[i]))
up.pop_back();
up.push_back (a[i]);
}
if (i==a.size()-1 || ccw (p1, a[i], p2)) {
while (down.size()>=2 && !ccw (down[down.size()-2],
down[down.size()-1], a[i]))
down.pop_back();
down.push_back (a[i]);
}
}
a.clear();for (size_t i=0; i<up.size(); ++i)
a.push_back (up[i]);
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin>>n;
    vector<pt> a(n);
    for (int i = 0; i<n; i++)
    {
        ll x, y;
        cin>>x>>y;
        a[i].x = x;
        a[i].y = y - x*x;
    }
    /*for (auto it: a) cout<<it.x<<' '<<it.y<<endl;
    cout<<endl;*/
    convex_hull(a);
    /*for (auto it: a) cout<<it.x<<' '<<it.y<<endl;
    cout<<a.size()-1;*/
    
    int k = a.size();
    int ans = k-1;
    for (int i = 0; i<k-1; i++) if (a[i].x==a[i+1].x) ans--;
    cout<<ans;
    

    
}