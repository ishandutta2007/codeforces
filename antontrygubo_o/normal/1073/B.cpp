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
    int b[n];
    for (int i = 0; i<n; i++) {cin>>a[i]; a[i]--;}
    for (int i = 0; i<n; i++) {cin>>b[i]; b[i]--;}
    int pos[n];
    for (int i = 0; i<n; i++) pos[a[i]] = i;
    int pos1[n];
    for (int i = 0; i<n; i++) pos1[i] = pos[b[i]];
    int x = -1;
    for (int i = 0; i<n; i++)
    {
        if (pos1[i]>x) {cout<<pos1[i]-x<<' '; x = pos1[i];}
        else cout<<0<<' ';
    }
    
}