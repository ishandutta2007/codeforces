#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0;char s=getchar();
	while(!isdigit(s))s=getchar();
	while(isdigit(s))x=(x<<1)+(x<<3)+s-'0',s=getchar();
	return x;
}
int t,n,x;
int main()
{
	t=read();
	for(int i=0;i<t;i++){
		n=read();
		int ans1=0,ans2=0;
		for(int j=0;j<n;j++){
			x=read();
			if(x>ans1)ans2=ans1,ans1=x;
			else if(x>=ans2)ans2=x;
		}
		cout<<min(ans2-1,n-2)<<endl;
	}
	return 0;
}