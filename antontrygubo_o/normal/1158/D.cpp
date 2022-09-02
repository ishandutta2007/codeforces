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

struct point {
    int x, y;
};

bool isNotRightTurn(const point &a, const point &b, const point &c) {
    long long cross = (long long) (a.x - b.x) * (c.y - b.y) - (long long) (a.y - b.y) * (c.x - b.x);
    long long dot = (long long) (a.x - b.x) * (c.x - b.x) + (long long) (a.y - b.y) * (c.y - b.y);
    return cross < 0 || (cross == 0 && dot <= 0);
}

vector<point> convex_hull(vector<point> points) {
    sort(points.begin(), points.end(), [](auto a, auto b) { return a.x < b.x || a.x == b.x && a.y < b.y; });
    int n = points.size();
    vector<point> hull;
    for (int i = 0; i < 2 * n - 1; i++) {
        int j = i < n ? i : 2 * n - 2 - i;
        while (hull.size() >= 2 && isNotRightTurn(hull.end()[-2], hull.end()[-1], points[j]))
            hull.pop_back();
        hull.push_back(points[j]);
    }
    hull.pop_back();
    return hull;
}

bool check(point a, point b)
{
    return a.x==b.x&&a.y==b.y;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<point> a(n);
    for (int i = 0; i<n; i++) cin>>a[i].x>>a[i].y;
    vector<point> saver(n);
    for (int i = 0; i<n; i++) saver[i] = a[i];
    string s;
    cin>>s;
    s+='L';
    auto hull = convex_hull(a);
    //for (auto it: hull) cout<<it.x<<' '<<it.y<<endl;
    vector<point> answer;
    answer.push_back(hull[0]);
    if (s[0]=='R') answer.push_back(hull[1]);
    else answer.push_back(hull[hull.size()-1]);
    int j = 0;
    while (!check(a[j], hull[0])) j++;
    a.erase(a.begin()+j);
    for (int i = 1; i<=n-2; i++)
    {
        hull = convex_hull(a);
        int j = 0;
        while (!check(hull[j], answer[answer.size()-1])) j++;
        if (s[i]=='R') answer.push_back(hull[(j+1)%hull.size()]);
        else answer.push_back(hull[(j+hull.size()-1)%hull.size()]);
        for (int k = 0; k<a.size(); k++) if (check(a[k], hull[j])) a.erase(a.begin() + k);
    }

    for (int i = 0; i<n; i++)
    {
        int j = 0;
        while (!check(answer[i], saver[j])) j++;
        cout<<j+1<<' ';
    }


    
    

}