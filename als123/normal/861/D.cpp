#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
struct SAM{
	int par,max,a[10];
}sam[1400000];int root=1,tot=1;
int n;
int check[1400000];
int addsam(int p,int c)
{
    int np=++tot;
    sam[np].max=sam[p].max+1;
    for(;p&&!sam[p].a[c];p=sam[p].par) sam[p].a[c]=np;
    if(!p) sam[np].par=root;
    else
    {
        int q=sam[p].a[c];
        if(sam[q].max==sam[p].max+1) sam[np].par=q;
        else
        {
            int nq=++tot;
            sam[nq]=sam[q];sam[nq].max=sam[p].max+1;
            sam[q].par=sam[np].par=nq;
            for(;p&&sam[p].a[c]==q;p=sam[p].par) sam[p].a[c]=nq;
        }
    }
    return np;
}
char s[70010][15];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s[i]+1);
		int p=root;
	    for(int k=1;k<=9;k++)
	        p=addsam(p,s[i][k]-'0');
	}
	for(int i=1;i<=n;i++)
	{
		for(int k=1;k<=9;k++)
		{
			int x=root;
			for(int j=k;j<=9;j++)
			{
				x=sam[x].a[s[i][j]-'0'];
				if(check[x]==0) check[x]=i;
				else if(check[x]!=i) check[x]=-1;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		int ans=15,l,r;
		for(int k=1;k<=9;k++)
		{
			int x=root;
			for(int j=k;j<=9;j++)
			{
				x=sam[x].a[s[i][j]-'0'];
				if(check[x]==i)
					if(ans>j-k+1) ans=j-k+1,l=k,r=j;
			}
		}
		for(int j=l;j<=r;j++) printf("%c",s[i][j]);printf("\n");
	}
}