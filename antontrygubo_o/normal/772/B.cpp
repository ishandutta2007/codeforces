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

int p = 10007;


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


struct point
{
    ll x;
    ll y;
};

ll triangle_area (point a1, point a2, point a3) {
return abs((a2.x - a1.x) * (a3.y - a1.y) - (a2.y - a1.y) * (a3.x - a1.x));
}



double d(point a, point b)
{
    return sqrt( double((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y)));
}

vector<point> a;

int n;
/*
double solve(int i, int j)
{
    
    double maxx = 0;
    int i1 = i;
    int j1 = j;
    while (j-i>2)
    {
        int l = i + (j-i)/3;
        int r = j - (j-i)/3;
        if (triangle_area(a[i1], a[j1], a[l])>triangle_area(a[i1], a[j1], a[r])) j = r;
        else i = r;
    }
    
    for (int k = i; k<=j; k++) maxx = max(maxx, triangle_area(a[i1], a[k], a[j1]));
    
    i = i1;
    j = j1;
    
    
}*/

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin>>n;

    a.resize(n);

    for (int i = 0; i<n; i++) cin>>a[i].x>>a[i].y;
    
    long double minn = 1000000000000.0;
    
    for (int i = 0; i<n; i++)
    {
        int j = (i+1)%n;
        for (int k = 0; k<n; k++) if (k!=j && k!=i)
        {
            //cout<<i<<' '<<j<<' '<<k<<": "<<triangle_area(a[i], a[j], a[k])<<endl;
            minn = min(minn, (long double)(triangle_area(a[i], a[j], a[k])/d(a[i], a[j])));
            minn = min(minn, (long double)(triangle_area(a[i], a[j], a[k])/d(a[i], a[k])));
            minn = min(minn, (long double)(triangle_area(a[i], a[j], a[k])/d(a[k], a[j])));
        }
    }
    
    minn/=2.0;
    
    cout<<setprecision(20)<<minn;
    
    /*for (int i = 0; i<n; i++)
    for (int j = i+1; j<n; j++)
    maxx = max(maxx, solve(i, j));
    cout<<maxx;*/
    
    
    
}