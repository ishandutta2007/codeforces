#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
int m,n,k,t,a[N],mx[N];
struct trap{
	int l,r,d;
}c[N];
bool cmp(trap a,trap b){return a.l<b.l;}
bool check(int x)
{
	int v=a[m-x+1],r=0,lp=0,rp=0;
	for(int i=1;i<=k;i++)
		if(c[i].d>v){
			if(c[i].l<=rp)rp=max(rp,c[i].r);
			else r+=(rp-lp)*3+c[i].l-rp-1,lp=c[i].l-1,rp=c[i].r;
		}
	r+=(rp-lp)*3+(n+1-rp);
	return r<=t;
}
int ef(int l,int r)
{
	if(l==r)return l;
	int m=l+r>>1;
	if(check(m))return ef(m+1,r);
	else return ef(l,m);
}
int main()
{
	cin>>m>>n>>k>>t;
	for(int i=1;i<=m;i++)
		cin>>a[i];
	sort(a+1,a+m+1);
	for(int i=1;i<=k;i++)
		cin>>c[i].l>>c[i].r>>c[i].d;
	sort(c+1,c+k+1,cmp);
	cout<<ef(1,m+1)-1;
    return 0;
}