#include<cstdio>
#include<set>
#define Mx 31
#define LL long long
using namespace std;
int q,ans,tot;LL t;char ch;
int pw[32];LL sum[32];
multiset<int> s[32];
int main()
{
	scanf("%d",&q),pw[0]=1;
	for(int i=1;i<=Mx;++i)pw[i]=(pw[i-1]<<1);
	for(int x;q--;)
	{
		do ch=getchar();while(ch!='+' && ch!='-');
		scanf("%d",&x),t=0,ans=(tot+=(ch=='+'? 1:-1));
		if(ch=='+')
		{
			for(int i=1;i<=Mx;++i)
				if(x<pw[i])
				{
					s[i].insert(x),sum[i]+=x;
					break;
				}
		}
		else
		{
			for(int i=1;i<=Mx;++i)
				if(x<pw[i])
				{
					s[i].erase(s[i].find(x)),sum[i]-=x;
					break;
				}
		}
		for(int i=1;i<=Mx;++i)ans-=(!s[i].empty() && (*s[i].begin())>2*t),t+=sum[i];
		printf("%d\n",ans);
	}
	return 0;
}