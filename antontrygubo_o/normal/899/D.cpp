#include<iostream>

using namespace std;

int main()
{
long long n;
cin>>n;
int k = -1;
long long n1 = 2*n;
while (n1) {n1 /=10; k++;}
if (n==1) {cout<<0; return 0;}
if (n==2) {cout<<1; return 0;}
if (n==3) {cout<<3; return 0;}
if (n==4) {cout<<6; return 0;}

long long a = 1;
for (int i = 0; i<k; i++) a*=10;
long long c = n/a;
long long r = n-c*a;
long long number = c*(n+r);

if ((r>=a/2)&&(r!=a-1)) number += 2*(r+1)-a;
if (r==a-1) number += 2*r-a;
cout<<number/2;

}