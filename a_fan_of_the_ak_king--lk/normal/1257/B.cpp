#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ri register int
const long double PI=3.141592653589793238462643383279;
const int N=500005,M=1000000007;
int n,x,a,b,t,y;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&x,&y);
		if(x==2||x==3)
			if(y==2||y==3||y==1)
				cout<<"yes"<<endl;
			else
				cout<<"no"<<endl;
		if(x==1)
			if(y==1)
				cout<<"yes"<<endl;
			else
				cout<<"no"<<endl;
		if(x>3)
			cout<<"yes"<<endl;
	}
}