#include<bits/stdc++.h>
using namespace std;
int n,t=-1;
int a[65542],b[65542];
vector<int> vec[65542];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(n),a[1]=0;
	for(int i=2;i<=n;++i)printf("XOR %d %d\n",1,i),fflush(stdout),read(a[i]);
	for(int i=1;i<=n;++i)vec[a[i]].push_back(i);
	for(int i=0;i<n;++i)if(vec[i].size()>1){t=i;break;}
	if(~t)
	{
		printf("OR %d %d\n",vec[t][0],vec[t][1]),fflush(stdout),read(b[t=vec[t][0]]);
		for(int i=n;i>2;--i)a[i]^=a[i-1];
		for(int i=t-1;i;--i)a[i]^=a[i+1];
		for(int i=t+2;i<=n;++i)a[i]^=a[i-1];
		for(int i=1;i<t;++i)b[i]=a[i+1]^b[t];
		for(int i=t+1;i<=n;++i)b[i]=a[i]^b[t];
	}
	else
	{
		printf("AND 1 %d\n",vec[1][0]),fflush(stdout),read(b[1]);
		printf("AND 1 %d\n",vec[2][0]),fflush(stdout),read(t),b[1]|=t;
		for(int i=2;i<=n;++i)b[i]=a[i]^b[1];
	}
	printf("!");
	for(int i=1;i<=n;++i)printf(" %d",b[i]);
	fflush(stdout);return 0;
}