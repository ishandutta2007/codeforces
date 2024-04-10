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

vector<ld> solve(ld sum, ld prod)
{
    ld diff = sqrt(max(sum*sum - 4.0*prod, (ld)(0.0)));
    return {(max((ld)(0), sum-diff))/2.0, (sum+diff)/2.0};
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin>>n;
    vector<ld> maxx(n);
    vector<ld> minn(n);
    get(maxx);
    get(minn);
    vector<ld> sum(n);
    for (int i = 0; i<n; i++) sum[i] = maxx[i]+minn[i];
    vector<ld> a(n);
    vector<ld> b(n);
    ld A = 0.0;
    ld B = 0.0;
    //print(sum);
    for (int i = 0; i<n-1; i++)
    {
        auto t = solve(sum[i]+A+B, maxx[i] + A*B);
        //print(t);
        //cout<<A<<' '<<B<<endl;
        if (A>B)
        {
            a[i] = t[1]-A;
            b[i] = t[0]-B;
            A = t[1];
            B = t[0];
        }
        else
        {
            a[i] = t[0]-A;
            b[i] = t[1]-B;
            A = t[0];
            B = t[1];
        }
    }
    a[n-1] = 1.0-A;
    b[n-1] = 1.0-B;
    for (int i = 0; i<n; i++) cout<<setprecision(16)<<a[i]<<' ';
    cout<<endl;
    for (int i = 0; i<n; i++) cout<<setprecision(16)<<b[i]<<' ';
}