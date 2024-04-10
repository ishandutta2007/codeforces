#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int N=100005;

int n,k,m;
vector<int> vec[N];

int read()
{
    int x=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int main()
{
	n=read();k=read();m=read();
	for (int i=1;i<=n;i++)
	{
		int x=read();
		vec[x%m].push_back(x);
	}
	for (int i=0;i<m;i++)
		if (vec[i].size()>=k)
		{
			puts("Yes");
			for (int j=0;j<k;j++) printf("%d ",vec[i][j]);
			return 0;
		}
	puts("No");
	return 0;
}