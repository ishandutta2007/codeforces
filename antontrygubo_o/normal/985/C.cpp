#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll n, k, l;
    cin>>n>>k>>l;
    ll m = n*k;
    ll a[m];
    for (int i = 0; i<m; i++) cin>>a[i];
    sort(a, a+m);
    if (a[n-1]>a[0]+l) {cout<<0; return 0;}
    int idx = 0;
    while (idx<m&&a[idx]<=a[0]+l) idx++;
    idx--;
    ll summa = 0;
    while ((k*(n-1)>=idx)&&(idx>=0)) {summa+=a[idx]; idx--; n--;}

    for (int i = 0; i<n; i++) {summa+=a[i*k]; }
    cout<<summa;

}