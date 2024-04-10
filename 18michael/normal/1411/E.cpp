#include<cstdio>
#define LL long long
int n;LL T,k,k1;
LL cnt[26]={},pw[26];
char s[100002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void swap(LL &x,LL &y)
{
	int z=x;x=y,y=z;
}
inline LL abs(LL x)
{
	return x>0? x:-x;
}
inline LL min(LL a,LL b)
{
	return a<b? a:b;
}
int main()
{
	read(n),read(T),scanf("%s",s+1),pw[0]=1;
	for(int i=1;i<26;++i)pw[i]=(pw[i-1]<<1);
	T+=pw[s[n-1]-'a'],T-=pw[s[n]-'a'];
	for(int i=1;i<n-1;++i)++cnt[s[i]-'a'];
	for(int i=25;~i;--i)
	{
		k=abs(T/pw[i]),k1=k+(T-k*pw[i]*(T>0? 1:-1)>0? -1:1);
		if(abs(T-pw[i]*k)>abs(T-pw[i]*k1))swap(k,k1);
		k1=min(k,cnt[i]),T-=k1*pw[i]*(T>0? 1:-1),cnt[i]-=k1;
		if(cnt[i]&1)T+=(T<0? pw[i]:-pw[i]);
	}
	puts(T? "No":"Yes");
	return 0;
}