#include <bits/stdc++.h>

using namespace std;

bool issqr (int n)
{
    if (n<0) return false;
    int k = sqrt(n);
    if (k*k==n) return true;
    return false;
}

int main() 
{
int n;
cin>>n;
int a;
int maxx = -100000000;
for (int i = 0; i<n; i++)
{
    cin>>a; if (!issqr(a)) maxx = max(a, maxx);
}
cout<<maxx;
}