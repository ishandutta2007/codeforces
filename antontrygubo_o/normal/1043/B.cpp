#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll p = 998244353;

vector<int> b;

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i = 0; i<n; i++) cin>>a[i];
    b.resize(n);
    b[0] = a[0];
    for (int i = 1; i<n; i++) b[i] = a[i] - a[i-1];
    
    vector<bool> check(n+1, 1);
    for (int i = 0; i<n; i++)
    for (int j = i+1; j<n; j++)
    if (b[j]!=b[i]) check[j-i] = 0;
    
    check[0] = 0;
    int counter = 0;
    for (int i = 0; i<=n; i++) if (check[i]) counter++;
    cout<<counter<<endl;
    for (int i = 0; i<=n; i++) if (check[i]) cout<<i<<' ';
    
}