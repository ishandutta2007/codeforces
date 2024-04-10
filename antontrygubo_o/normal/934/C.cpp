#include<bits/stdc++.h>
using namespace std;

int main()
{
int n;
cin>>n;
int a[n];
for (int i = 0; i<n; i++) cin>>a[i];
int one[n] = {0};
one[0] = 2-a[0];
for (int i = 1; i<n; i++)
{
    one[i] = one[i-1];
    if (a[i]==1) one[i]++;
}

int two[n] = {0};
two[n-1] = a[n-1]-1;
for (int i = n-2; i>=0; i--)
{
    two[i] = two[i+1];
    if (a[i]==2) two[i]++;
}


int max1[n] = {0};
max1[0] = 1;
for (int i = 1; i<n; i++)
{
    max1[i] = max1[i-1];
    if (a[i]==2) max1[i]++;
    max1[i] = max(max1[i], one[i]);
}

int max2[n] = {0};
max2[n-1] = 1;
for (int i = n-2; i>=0; i--)
{
    max2[i] = max2[i+1];
    if (a[i]==1) max2[i]++;
    max2[i] = max(max2[i], two[i]);
}

int maxx = 0;
for (int i = 0; i<n-1; i++) maxx = max(maxx, max1[i]+max2[i+1]);
maxx = max(maxx, one[n-1]);
maxx = max(maxx, two[0]);
cout<<maxx;
}