#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define mp make_pair

void print(vector<auto> &a)
{
    for (int i = 0; i<a.size(); i++) cout<<a[i]<<' ';
    cout<<endl;
}

void get(vector<auto> &a)
{
    for (int i = 0; i<a.size(); i++) cin>>a[i];
}

const ll p = 998244353;

int mul(int a, int b) {
    return (1LL * a * b) % p;
}

int add(int a, int b) {
    int s = (a+b);
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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int n;
    cin>>n;
    vector<int> a(n);
    get(a);
    
    vector<int> b;
    b.push_back(a[0]);
    for (int i = 1; i<n; i++) if (a[i]!=a[i-1]) b.push_back(a[i]);
    
    a = b;
    n = a.size();
    //print(a);
    vector<vector<int>> dp(5005, vector<int>(5005));
    for (int i = 0; i<n; i++) dp[i][i] = 0;
    
    for (int j = 1; j<n; j++)
    for (int i = 0; i<n-j; i++)
    {
        dp[i][i+j] = max(dp[i][i+j-1], dp[i+1][i+j]);
        if (a[i]==a[i+j]) dp[i][i+j] = dp[i+1][i+j-1] + 1; 
    }
    
    cout<<n-1 - dp[0][n-1];
    
}