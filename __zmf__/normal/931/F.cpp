#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int a[N],d1[N],d2[N],n,m,ans[N],now,len;
int x,y;
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
int main() {
    m=read(),n=read();
    for(int i=1;i<=m;i++)
    {
    	x=read(),y=read();a[x]++,a[y+1]--;
	}
	for(int i=1;i<=n;i++)
		a[i]=a[i-1]+a[i];
	//for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	//cout<<endl;
    int len1=1,len2=1;
    d1[1]=d2[1]=a[1];
    for(int i=2;i<=n;i++) 
	{
        if(d2[len2]<=a[i])d2[++len2]=a[i],ans[i]=len2;
        else
		{
			ans[i]=upper_bound(d2+1,d2+1+len2,a[i])-d2,*upper_bound(d2+1,d2+1+len2,a[i])=a[i];
		}
	//	cout<<ans[i]<<" ";
    }
    //cout<<endl;
    for(int i=1;i<=n/2;i++)swap(a[i],a[n-i+1]);
    len1=1,len2=1;
    d1[1]=d2[1]=a[1];len=ans[n];
    for(int i=2;i<=n;i++) 
	{
		if(d1[len1]<=a[i])d1[++len1]=a[i],now=len1;
        else 
		{
			now=upper_bound(d1+1,d1+1+len1,a[i])-d1,*upper_bound(d1+1,d1+1+len1,a[i])=a[i];
		}
	//	cout<<now<<" ";
       	len=max(len,now+ans[n-i+1]-1);
    }
    //cout<<endl;
    printf("%d\n",len);
    return 0;
}
/*
11 11
1 6
2 6
3 6
4 6
5 6
6 6
7 11
7 10
7 9
7 8
7 7
*/