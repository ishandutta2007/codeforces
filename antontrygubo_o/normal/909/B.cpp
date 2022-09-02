#include<iostream>
#include<algorithm>
#include<random>
#include<string>
using namespace std;


int main()
{
int n;
cin>>n;
if (n%2==1) cout<<(n+1)*(n+1)/4;
if (n%2==0) cout<<n*(n+2)/4;
}