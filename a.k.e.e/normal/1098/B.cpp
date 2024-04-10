#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
const int MAXN=300005;
int calc(char c)
{
	if(c=='A')return 0;
	if(c=='C')return 1;
	if(c=='G')return 2;
	return 3;
}
char abc[4]={'A','C','G','T'};

int n,m;
char str[MAXN];
int a[MAXN],b[MAXN],ans[MAXN];

int p[5]={0,1,2,3};

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
    	scanf("%s",str);
    	for(int j=0;j<m;j++)
    		a[i*m+j]=calc(str[j]);
    }
    int Min=n*m+5;
    for(int i1=0;i1<4;i1++)
    	for(int i2=i1+1;i2<4;i2++)
    	{
    		int i3=-1,i4=-1;
    		for(int k=0;k<4;k++)
    			if(i1!=k && i2!=k)i3<0?(i3=k):(i4=k);
    		int cur=0;
    		for(int i=0;i<n;i++)
    		{
    			int x,y,s=0,t=0;
    			if(!(i&1))x=i1,y=i2;
    			else x=i3,y=i4;
    			for(int j=0;j<m;j++)
    				if(j&1)s+=(a[i*m+j]!=y),t+=(a[i*m+j]!=x);
    				else s+=(a[i*m+j]!=x),t+=(a[i*m+j]!=y);
    			if(s<t)for(int j=0;j<m;j++)b[i*m+j]=(j&1)?y:x;
    			else for(int j=0;j<m;j++)b[i*m+j]=(j&1)?x:y;
    		}
    		for(int i=0;i<n;i++)
    			for(int j=0;j<m;j++)
    				if(b[i*m+j]!=a[i*m+j])++cur;
    		if(cur<Min){Min=cur;memcpy(ans,b,sizeof(ans));}
    		cur=0;
    		for(int j=0;j<m;j++)
    		{
    			int x,y,s=0,t=0;
    			if(!(j&1))x=i1,y=i2;
    			else x=i3,y=i4;
    			for(int i=0;i<n;i++)
    				if(i&1)s+=(a[i*m+j]!=y),t+=(a[i*m+j]!=x);
    				else s+=(a[i*m+j]!=x),t+=(a[i*m+j]!=y);
    			if(s<t)for(int i=0;i<n;i++)b[i*m+j]=(i&1)?y:x;
    			else for(int i=0;i<n;i++)b[i*m+j]=(i&1)?x:y;
    		}
    		for(int i=0;i<n;i++)
    			for(int j=0;j<m;j++)
    				if(b[i*m+j]!=a[i*m+j])++cur;
    		if(cur<Min){Min=cur;memcpy(ans,b,sizeof(ans));}
    	}
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<m;j++)
    		putchar(abc[ans[i*m+j]]);
    	putchar('\n');
    }
    return 0;
}