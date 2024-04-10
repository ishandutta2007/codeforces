#include<cstdio>
#include<cstring>
#include<algorithm>
using std::max;
#include<set>
typedef long long ll;
typedef double db;
int n;
int l[111111],r[111111];
int d[111111];
int stk[111111],top; 
void exec()
{
	scanf("%d",&n);
	register int i;
	top=0;
	for(i=1;i<=n;i++)
		scanf("%d",&l[i]),d[i]=r[i]=0;
	for(i=1;i<=n;i++)
		if(l[i]^l[i-1])d[i]=l[i],r[l[i]]=1;
	for(i=n;i;i--)
		if(!r[i])stk[++top]=i;
	for(i=1;i<=n;i++)
		if(!d[i])d[i]=stk[top],top--;
	int tmp=0;
	for(i=1;i<=n;i++)
	{
		tmp=max(tmp,d[i]);
		if(tmp^l[i])goto FAIL;
	}
	for(i=1;i<=n;i++)
		printf("%d%c",d[i],(i^n)?' ':'\n');
	return;
	FAIL:puts("-1");
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)exec();
}