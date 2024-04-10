#include<bits/stdc++.h>
#define Mx 200000
#define LL long long
using namespace std;
int n,m,base,mod;
bool ok;
char s[200002];
LL S[26],T[26],pw[200002];
LL Hs[26][200002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline LL RND()
{
	LL res=rand();
	res*=rand(),res^=rand();
	res*=rand(),res^=rand();
	res*=rand(),res^=rand();
	res*=rand(),res^=rand();
	return res<0? -res:res;
}
inline bool check(int x)
{
	for(int i=2;i*i<=x;++i)
		if(!(x%i))
			return 0;
	return 1;
}
inline void init()
{
	pw[0]=1,base=RND()%1000+233,mod=RND()%100000000+998244353;
	if(!(mod&1))++mod;while(!check(mod))mod+=2;
	for(int i=1;i<=Mx;++i)pw[i]=(pw[i-1]*base)%mod;
}
int main()
{
	srand(time(NULL)),init(),read(n),read(m),scanf("%s",s+1);
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<26;++j)Hs[j][i]=(Hs[j][i-1]*base)%mod;
		Hs[s[i]-'a'][i]=(Hs[s[i]-'a'][i]+1)%mod;
	}
	for(int x,y,z;m--;)
	{
		read(x),read(y),read(z);
		for(int i=0;i<26;++i)
		{
			if((S[i]=(Hs[i][x+z-1]-Hs[i][x-1]*pw[z])%mod)<0)S[i]+=mod;
			if((T[i]=(Hs[i][y+z-1]-Hs[i][y-1]*pw[z])%mod)<0)T[i]+=mod;
		}
		sort(S,S+26),sort(T,T+26),ok=1;
		for(int i=0;i<26;++i)
			if(S[i]!=T[i])
			{
				ok=0;
				break;
			}
		puts(ok? "YES":"NO");
	}
	return 0;
}//