#include<bits/stdc++.h>
using namespace std;
int n,m,z;
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
int main()
{
	cin>>n>>m>>z;
	cout<<z/(int)(n*m/gcd(n,m));
	return 0;
}