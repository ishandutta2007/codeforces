//zhouakngyang txdy!
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
#define Macesuted cout<<"kawaii"<<endl
#define MatrixCascade cout<<"npsl"<<endl
#define Karry5307 cout<<"nmsl"<<endl
using namespace std;
//#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
const int N=5009;
int n;
int ans[2][N],a[N],b[N],flag,vis[N],kk;
int res[N];
int main()
{
	n=read();
	for(int i=0;i<n;i++)
	{
		printf("? %d %d\n",0,i);
		fflush(stdout);
		ans[0][i]=read();	
	}
	for(int i=0;i<n;i++)
	{
		printf("? %d %d\n",i,0);
		fflush(stdout);
		ans[1][i]=read();
	}
	for(int i=0;i<n;i++)
	{
	//	cout<<i<<"qwq"<<endl;
		flag=0;
		b[0]=i;
		for(int j=0;j<n;j++)a[j]=ans[1][j]^i;
		for(int j=1;j<n;j++)b[j]=ans[0][j]^a[0];
		for(int j=0;j<n;j++)
			if(a[b[j]]!=j)flag=1;
		memset(vis,0,sizeof(vis));
		//for(int j=0;j<n;j++)cout<<a[j]<<" "<<b[j]<<endl;
		//cout<<"--------"<<endl;
		for(int j=0;j<n;j++)
		{
			if(vis[a[j]])flag=1;vis[a[j]]=1;
		}
		memset(vis,0,sizeof(vis));
		for(int j=0;j<n;j++)
		{
			if(vis[b[j]])flag=1;vis[b[j]]=1;
		}
		if(flag)continue;
		kk++;
		if(kk==1)
		{
			for(int j=0;j<n;j++)res[j]=a[j];
		}
	}
	puts("!");
	cout<<kk<<endl;
	for(int i=0;i<n;i++)cout<<res[i]<<" ";
	return 0;
}

/*
3
0
1
2
0
1
2
*/
/*
3 1 2 0
3 1 2 0
*/
/*
4
0
2
1
3
0
2
1
3
*/