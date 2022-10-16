#include<bits/stdc++.h>
using namespace std;
#define abab ababa
int i,n;
int main()
{
	cin>>n,n*=2;
	i=sqrt(n);
	if(i*(i+1)==n)cout<<"YES";
	else cout<<"NO";
	return 0;
}