#include<cstdio>
int n,cnt,Test_num;bool ok;
int rt[26];char A[100002],B[100002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void getroot(int x)
{
	if(x==rt[x])return ;
	getroot(rt[x]),rt[x]=rt[rt[x]];
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(n),scanf("%s%s",A,B),ok=1,cnt=0;
		for(int i=0;i<26;++i)rt[i]=i;
		for(int i=0;i<n;++i)
		{
			if(A[i]>B[i])
			{
				ok=0;
				break;
			}
			if(A[i]<B[i])
			{
				getroot(A[i]-'a'),getroot(B[i]-'a');
				if(rt[A[i]-'a']!=rt[B[i]-'a'])rt[rt[A[i]-'a']]=rt[B[i]-'a'];
			}
		}
		if(!ok)puts("-1");
		else
		{
			for(int i=0;i<26;++i)getroot(i),cnt+=(rt[i]!=i);
			printf("%d\n",cnt);
		}
	}
	return 0;
}