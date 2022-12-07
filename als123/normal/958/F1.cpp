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

const int maxn = 210;

int n,m,sum,num;
int a[maxn],b[maxn],s[maxn];

void add(int x)
{
	if(s[x]==b[x]) num++;
	s[x]++;
	if(s[x]==b[x]) num--;
}
void dec(int x)
{
	if(s[x]==b[x]) num++;
	s[x]--;
	if(s[x]==b[x]) num--;
}

int main()
{
	//freopen("tmp.in","r",stdin);
	//freopen("tmp.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=m;i++) scanf("%d",&b[i]),sum+=b[i],num+=b[i]!=0;
	
	int ok=0;
	for(int r=1;r<=n;r++)
	{
		add(a[r]);
		if(r-sum>0) dec(a[r-sum]);
		if(!num) ok=1;
	}
	puts(ok?"YES":"NO");
	
    return 0;
}