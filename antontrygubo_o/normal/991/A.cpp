#include<bits/stdc++.h>
using namespace std;

#define ll long long


int main()
{
int a, b, c, n;
cin>>a>>b>>c>>n;
if (a<c) {cout<<-1; return 0;}
if (b<c) {cout<<-1; return 0;}
if (n-a-b+c<=0) {cout<<-1; return 0;}
cout<<n-a-b+c;
}