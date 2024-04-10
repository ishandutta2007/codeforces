#include <bits/stdc++.h>

using namespace std;

int main() 
{
int n;
cin>>n;
int a[n];
for (int i = 0; i<n; i++) cin>>a[i];
bool check = true;
for (int i = 0; i<n-1; i++)
if (fabs(a[i+1]-a[i])>1) check = false;
if (check) cout<<"YES";
else cout<<"NO";
}