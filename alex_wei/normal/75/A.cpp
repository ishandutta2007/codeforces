#include<bits/stdc++.h>
using namespace std;
int ez(int a)
{
	int f[10],cnt=0;
	while(a)f[++cnt]=a%10,a/=10;
	for(int i=cnt;i>0;i--)
		if(f[i])a=a*10+f[i];
	return a;
}
int x,y;
int main()
{
	cin>>x>>y;
	if(ez(x)+ez(y)==ez(x+y))cout<<"YES";
	else cout<<"NO";
	return 0;
}