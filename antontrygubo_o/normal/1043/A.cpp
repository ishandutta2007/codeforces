#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll p = 998244353;



int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    int a[n];
    int maxx = 0;
    for (int i = 0; i<n; i++) {cin>>a[i]; maxx = max(maxx, a[i]);}
    int sum = 0;
    for (int i = 0; i<n; i++) sum+=a[i];
    sum*=2;
    int k = sum/n+1;
    cout<<max(k, maxx);
}