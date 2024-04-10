#include<cstdio>
int n,r1,r2,ans;
int a[100002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline int min(int a,int b)
{
	return a<b? a:b;
}
int main()
{
	read(n),a[0]=a[n+1]=0,ans=n+1;
	for(int i=1;i<=n;++i)read(a[i]);
	for(int i=2;i<n;++i)if((a[i-1]^a[i])>a[i+1] || a[i-1]>(a[i]^a[i+1]))return 0&puts("1");
	for(int i=1;i<=n;++i)a[i]^=a[i-1];
	for(int i=1;i<=n;++i)
		for(int j=i;j<n;++j)
			for(int k=j+1;k<=n;++k)
				for(int l=k;l<=n;++l)
					if((a[j]^a[i-1])>(a[l]^a[k-1]))
						ans=min(ans,j-i+l-k);
	return 0&printf("%d",ans>n? -1:ans);
}