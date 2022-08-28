#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2222;
int n,a[N],x[N],y[N],p[N],f[N];
bool cmp(int i,int j){
	return (LL)x[i]*y[j]-(LL)x[j]*y[i]>0;
}
void ff(){
	int i,x;
	for(i=1;i<=n;i++)
		f[i]=0;
	for(i=1;i<=n;i++){
		if(!f[i]){
			f[i]=i;
			for(x=a[i];x!=i;x=a[x])
				f[x]=i;
		}
	}
}
vector<int> ans0,ans1;
void ans(int x,int y){
	ans0.push_back(x);
	ans1.push_back(y);
	swap(a[x],a[y]);
}
int main(){
	int i,o,l,e;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d%d%d",x+i,y+i,a+i);
	o=0;
	for(i=1;i<=n;i++)
		if(a[i]!=i&&(!o||x[i]<x[o]))
			o=i;
	if(o==0){
		printf("0");
		return 0;
	}
	x[0]=x[o],y[0]=y[o];
	for(i=1;i<=n;i++)
		x[i]-=x[0],y[i]-=y[0];
	l=0;
	for(i=1;i<=n;i++)
		if(i!=o&&a[i]!=i)
			p[++l]=i;
	sort(p+1,p+l+1,cmp);
	while(1){
		ff();
		e=0;
		for(i=1;i<l;i++){
			if(f[p[i]]!=f[p[i+1]]){
				ans(p[i],p[i+1]);
				e=1;
				break;
			}
		}
		if(!e)
			break;
	}
	while(a[o]!=o){
		ans(o,a[o]);
	}
	printf("%d\n",ans0.size());
	for(i=0;i<ans0.size();i++)
		printf("%d %d\n",ans0[i],ans1[i]);
	return 0;
}