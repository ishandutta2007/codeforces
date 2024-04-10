#include<bits/stdc++.h>
using namespace std;

int main()
{
long long n;
cin>>n;
n++;
if (n==1) {cout<<0; return 0;}
if (n%2==1) cout<<n;
else cout<<n/2;

}