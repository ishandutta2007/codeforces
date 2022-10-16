#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+5;
struct num{
	int id,val;
	bool operator < (const num &v) const {
		return val<v.val;
	}
}a[N];
int n,c[N],d[N],pre[N];
ll ans;
void add(int x){
	while(x<=n)c[x]++,x+=x&-x;
}
void add2(int x){
	while(x<=n)d[x]++,x+=x&-x;
}
int query(int x){
	int ans=0;
	while(x)ans+=c[x],x-=x&-x;
	return ans;
}
int query2(int x){
	int ans=0;
	while(x)ans+=d[x],x-=x&-x;
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i].val),a[i].id=i;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)pre[i]=query(n-a[i].id+1),add(n-a[i].id+1);
	for(int i=n;i;i--)ans=ans+1ll*pre[i]*query2(a[i].id),add2(a[i].id);
	cout<<ans<<endl;
	return 0;
}