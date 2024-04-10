#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string>
#include <map>

using namespace std;
const int maxn = 5005;

map<string,int> var;

int tp[maxn],n,m;
int op1[maxn],op[maxn],op2[maxn];
string num[maxn],cur,tmp;
int w0[maxn],w1[maxn];
int ans1[maxn],ans2[maxn];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("formula.in","r",stdin);
		freopen("formula.out","w",stdout);
	#endif
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++) {
		cin>>cur;var[cur]=i;
		cin>>tmp;cin>>tmp;
		if (tmp[0]>='0'&&tmp[0]<='1')
			num[i]=tmp;
		else {
			op1[i]=var[tmp];tp[i]=1;
			cin>>tmp;
			if (tmp[0]=='O') op[i]=1;
			if (tmp[0]=='X') op[i]=2;
			if (tmp[0]=='A') op[i]=3;
			cin>>tmp;op2[i]=var[tmp];
		}
	}
	for (int b=m-1;b>=0;b--)
	{
		int sum0=0,sum1=0;w0[0]=0;w1[0]=1;
		for (int i=1;i<=n;i++) {
			if (tp[i]) {
				if (op[i]==1) w0[i]=w0[op1[i]]|w0[op2[i]];
				if (op[i]==2) w0[i]=w0[op1[i]]^w0[op2[i]];
				if (op[i]==3) w0[i]=w0[op1[i]]&w0[op2[i]];
				if (op[i]==1) w1[i]=w1[op1[i]]|w1[op2[i]];
				if (op[i]==2) w1[i]=w1[op1[i]]^w1[op2[i]];
				if (op[i]==3) w1[i]=w1[op1[i]]&w1[op2[i]];
			}
			else {
				w0[i]=w1[i]=num[i][b]-'0';
			}
			sum0+=w0[i];sum1+=w1[i];
		}
		ans1[b]=ans2[b]=0;
		if (sum0<sum1) ans2[b]=1;
		if (sum0>sum1) ans1[b]=1;
	}
	for (int i=0;i<m;i++) printf("%d",ans1[i]);puts("");
	for (int i=0;i<m;i++) printf("%d",ans2[i]);puts("");
	return 0;
}