#include<iostream>
#include<algorithm>
#include<random>
using namespace std;

int gcd (int a, int b)
{
    if(a<b) swap(a,b);
    while ((a!=0)&&(b!=0))
    {
        a = a%b;
        swap (a, b);
    }
    return a+b;
}

int main()
{
int n;
cin>>n;
int k = n/2;
while ( gcd(k, n-k)!=1  ) k--;
cout<<k<<' '<<n-k;
}