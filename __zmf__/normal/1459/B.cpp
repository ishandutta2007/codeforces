#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
int taxi,n; 
long long ans,res;
int main()
{
//	taxi=read();
//	for(int ttt=1;ttt<=taxi;ttt++)
//	{
		n=read();
		if(n%2==0)
		{
			n=n/2+1;
			cout<<n*n<<endl;
			return 0;
		}
		n=(n+1)/2;
		
		cout<<2*(n+1)*n+res<<endl;
//	}
	return 0;
}