#include <bits/stdc++.h>
using namespace std;

int main() 
{
long long x, y;
cin>>y>>x;
if (x==0) {cout<<"No"; return 0;}
if ((x+y)%2==0) {cout<<"No"; return 0;}
if ((x==1)&&(y!=0)) {cout<<"No"; return 0;}
if (x>y+1) {cout<<"No"; return 0;}
cout<<"Yes";
}