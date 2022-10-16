#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0;char s=getchar();
	while(!isdigit(s))s=getchar();
	while(isdigit(s))x=(x<<1)+(x<<3)+s-'0',s=getchar();
	return x;
}
int n,a[200005],l,r,s;
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	l=1,r=n;
	while(l<=r){
		s++;
		if(a[l]==s){l++;continue;}
		if(a[r]==s){r--;continue;}
		cout<<"NO";
		exit(0);
	}
	cout<<"YES";
	return 0;
}