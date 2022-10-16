#include<bits/stdc++.h>
const int maxn=1<<20;
int n,m,k;
char s[1<<20];
int l[1<<20];
int r[1<<20];
int c[1<<20];
struct pii{int x,y;};
bool operator<(const pii&x,const pii&y)
{
	return x.x!=y.x?x.x<y.x:x.y<y.y;
}
int val(int x){return x?x:2e9;}
void exec()
{
	scanf("%d",&n);
	std::map<pii,int>M;
	std::map<int,int>mdl,mdr;
	auto upd=[&](int&x,int y)
	{
		if(!x)x=y;
		else if(x>y)x=y;
	};
	int minl=1e9,maxr=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",l+i,r+i,c+i);
		if(l[i]<minl)minl=l[i];
		if(r[i]>maxr)maxr=r[i];
		upd(M[pii{l[i],r[i]}],c[i]);
		upd(mdl[l[i]],c[i]);
		upd(mdr[r[i]],c[i]);
		printf("%d\n",std::min(mdr[maxr]+mdl[minl],val(M[pii{minl,maxr}])));
		//if(!M[pii{l[i],r[i]}])M[pii{l[i],r[i]}]=c[i];
		//else if(M[pii{l[i],r[i]}]>c[i])M[pii{l[i],r[i]}]=c[i];
	}
	for(int i=1;i<=n;i++)
		mdl[l[i]]=mdr[r[i]]=0;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)exec();
}