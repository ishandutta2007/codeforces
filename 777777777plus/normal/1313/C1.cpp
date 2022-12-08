#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+5;

int n;
ll a[N],b[N],res[N];
ll l[N],r[N];

void sol(ll *ans){
	static ll st[N],cnt[N],sum[N];
	int top=0;
	for(int i=1;i<=n;++i){
		ll c=1;
		while(top&&a[i]<st[top]){
			c+=cnt[top];
			top--;
		}
		++top;
		st[top]=a[i];
		cnt[top]=c;
		sum[top]=sum[top-1]+cnt[top]*a[i];
		ans[i]=sum[top];
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%I64d",&a[i]);
	sol(l);
	reverse(a+1,a+n+1);
	sol(r);
	reverse(r+1,r+n+1);
	reverse(a+1,a+n+1);
	int p=1;
	for(int i=2;i<=n;++i)
	if(l[i]+r[i]-a[i]>l[p]+r[p]-a[p]){
		p=i;
	}
	ll c=1e9;
	for(int i=p;i>=1;--i){
		res[i]=c=min(c,a[i]);
	}
	c=1e9;
	for(int i=p;i<=n;++i){
		res[i]=c=min(c,a[i]);
	}
	for(int i=1;i<=n;++i)printf("%I64d ",res[i]);
	printf("\n");
}