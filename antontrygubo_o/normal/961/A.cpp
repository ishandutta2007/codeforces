#include <bits/stdc++.h>

using namespace std;

int main() 
{
int n;
cin>>n;
int q;
cin>>q;
int a[n] = {0};
for (int i = 0; i<q; i++)
{
    int cur;
    cin>>cur;
    a[cur-1]++;
}
int minn = 1000000;
for (int i = 0; i<n; i++) minn = min(minn, a[i]);
cout<<minn;
}