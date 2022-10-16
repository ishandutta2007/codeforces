#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0;char s=getchar();
	while(!isdigit(s))s=getchar();
	while(isdigit(s))x=(x<<1)+(x<<3)+s-'0',s=getchar();
	return x;
}
int n,k,a[300002],b[300002],ans; 
int main()
{
	n=read(),k=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(i>1)b[i]=a[i]-a[i-1],ans+=b[i];
	}
	sort(b+2,b+n+1);
	for(int i=1;i<k;i++)
		ans-=b[n-i+1];
	cout<<ans;
	return 0;
}