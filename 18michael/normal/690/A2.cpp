#include<cstdio>
int n,s;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(n);
	if(n&1)n/=2;else{for(s=1;s<=n;s<<=1);n=(n-s/2)/2;}
	printf("%d",n);
	fclose(stdin);
	fclose(stdout);
	return 0;
}