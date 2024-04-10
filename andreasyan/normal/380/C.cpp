#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=1000*1002;
struct ban
{
	int ans,b,p;
};

int n;
char a[N];
ban t[N*4];
ban mer(ban a1,ban a2)
{
	ban res;
	int y=min(a1.b,a2.p);
	res.ans = a1.ans + a2.ans + y*2;
	res.b = a1.b + a2.b - y;
	res.p = a1.p + a2.p - y;
	return res;
}
void build(int tl,int tr,int pos)
{
	if(tl==tr)
	{
		if(a[tl]=='(')
			t[pos].b=1;
		else
			t[pos].p=1;
		return;
	}
	int m=(tl+tr)/2;
	build(tl,m,pos*2);
	build(m+1,tr,pos*2+1);
	/////
	t[pos]=mer(t[pos*2],t[pos*2+1]);
}
ban query(int tl,int tr,int l,int r,int pos)
{
	if(tl==l && tr==r)
	{
		return t[pos];
	}
	int m=(tl+tr)/2;
	if(r<=m)
		return query(tl,m,l,r,pos*2);
	else if(l>m)
		return query(m+1,tr,l,r,pos*2+1);
	else
		return mer(query(tl,m,l,m,pos*2),query(m+1,tr,m+1,r,pos*2+1));
}
int main()
{
	scanf("%s",&a);
	n=strlen(a);
	build(0,n-1,1);
	int q;
	scanf("%d",&q);
	for(int ii=0;ii<q;++ii)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		--l;
		--r;
		ban ans=query(0,n-1,l,r,1);
		printf("%d\n",ans.ans);
	}
//	system("pause");
	return 0;
}