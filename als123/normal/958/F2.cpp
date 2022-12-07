#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

const int maxn = 210000;

int n,m,num,sum,ans=-1;
int a[maxn],b[maxn],s[maxn];

void upd(int x) { if(ans==-1||ans>x) ans=x; }

int main()
{
	//freopen("tmp.in","r",stdin);
	//freopen("tmp.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=m;i++) scanf("%d",&b[i]),num+=b[i]==0,sum+=b[i];
	
	int l=1;
	for(int i=1;i<=n;i++)
	{
		s[a[i]]++; if(s[a[i]]==b[a[i]]) num++;
		while(s[a[l]]>b[a[l]]) s[a[l]]--,l++;
		if(num==m) upd(i-l+1-sum);
	}
	printf("%d\n",ans);
	
    return 0;
}