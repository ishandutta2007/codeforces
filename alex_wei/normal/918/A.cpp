#include<bits/stdc++.h>
using namespace std;
int n,c[1010],x=1,y=1,z; 
int main()
{
	c[1]=1;
	cin>>n;
	while(x+y<=n)z=x+y,c[z]=1,x=y,y=z;
	for(int i=1;i<=n;i++)
		cout<<(c[i]?'O':'o');
	return 0;
}