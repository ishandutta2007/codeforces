#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll p = 1e9 + 7;


int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i = 0; i<n; i++) cin>>a[i];
    set<int> b;
    if (a[0]!=0) {cout<<1; return 0;}
    b.insert(0);
    for (int i = 1; i<n; i++)
    {
        if (a[i]!=0 && b.find(a[i]-1)==b.end()) {cout<<i+1; return 0;}
        b.insert(a[i]);
    }
    cout<<-1;
     
}