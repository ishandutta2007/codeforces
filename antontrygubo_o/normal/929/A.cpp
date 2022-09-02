#include <bits/stdc++.h>
using namespace std;



int main()
{
int n, k;
cin>>n>>k;
int a[n];
for (int i = 0; i<n; i++) cin>>a[i];
for (int i = 0; i<n-1; i++) if (a[i+1]>a[i]+k) {cout<<-1; return 0;}
int best[n] = {0};
best[n-1] = 0;
int j = n-1;
for (int i = n-2; i>=0; i--)
{
    while (a[j]-k>a[i]) j--;
    best[i] = best[j]+1;
}
cout<<best[0];
}