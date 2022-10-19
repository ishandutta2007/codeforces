#include<cstdio>
#include<cstring>
#include<set>
using namespace std;
int n,l,ans=0;
char s[500002];
multiset<int> L,R;
multiset<int>::iterator it;
struct aaa
{
	int sum,mn,mn1;
}a[100002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch;do ch=getchar(),f|=(ch=='-');while(ch<'0' || ch>'9');
	do x=(x<<3)+(x<<1)+(ch^48),ch=getchar();while(ch>='0' && ch<='9');
	x=f? -x:x;
}
inline int min(int a,int b)
{
	return a<b? a:b;
}
int main()
{
	read(n);
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s+1),l=strlen(s+1),
		a[i].sum=a[i].mn=0;for(int j=1;j<=l;++j)a[i].sum+=(s[j]=='('? 1:-1),a[i].mn=min(a[i].sum,a[i].mn);
		a[i].sum=a[i].mn1=0;for(int j=l;j;--j)a[i].sum+=(s[j]==')'? 1:-1),a[i].mn1=min(a[i].sum,a[i].mn1);
		if(!a[i].mn && !a[i].mn1)++ans;
		else if(!a[i].mn)L.insert(-a[i].sum);
		else if(!a[i].mn1)R.insert(a[i].sum);
	}
	ans>>=1;
	while(!L.empty() && !R.empty())
	{
		it=R.find(*L.begin());
		if(it!=R.end())R.erase(it),++ans;
		L.erase(L.begin());
	}
	printf("%d",ans);
	return 0;
}