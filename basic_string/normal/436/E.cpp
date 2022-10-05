#include<bits/stdc++.h>
using namespace std;
using ll=long long;
priority_queue<pair<int,int>>u,v;
const int N=6e5+3;
bool b[N];
int a[N];
void clr(priority_queue<pair<int,int>>&q){while(q.size()&&b[q.top().second])q.pop();}
int main(){
	int n,w,i;
	long long s=0;
	for(scanf("%d%d",&n,&w),i=1;i<=n;++i)scanf("%d%d",a+i,a+i+n),a[i+n]-=a[i],u.push({-a[i],i}),v.push({-a[i]-a[i+n],i});
	while(w--){
		clr(u),clr(v),i=u.top().second,u.pop(),clr(u);
		if(w&&v.size()&&a[i]-u.top().first>-v.top().first)u.push({-a[i],i}),i=v.top().second,v.pop();
		if(i<=n)u.push({-a[i+n],i+n});
		b[i]=1,s+=a[i];
	}cout<<s<<'\n';
	for(i=1;i<=n;++i)if(b[i])putchar(b[i+n]?'2':'1');else putchar('0');
	return 0;
}