#include<bits/stdc++.h>

using namespace std;

#define ll long long

int siz;
struct Q{
	int l,r,id;
}q[100010];

bool cmp(Q a,Q b){
	if(a.l/siz==b.l/siz)return a.r<b.r;
	else return a.l<b.l;
}

int n,m;
ll v[100010],sum[100010];ll t[100010],a[100010],b[100010];
ll k;
ll nxt[100010],pre[100010];
ll ans[100010];

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>k;
	siz=sqrt(n);
	for(int i=1;i<=n;i++)
                cin>>t[i];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(t[i]==2)a[i]=-a[i];
		sum[i]=sum[i-1]+a[i];
		v[i]=sum[i];
		
	}
	int cnt;
	sort(v+1,v+n+2);
	cnt=unique(v+1,v+n+2)-v-1;
	
	for(int i=1;i<=cnt;i++){
		ll x=v[i]+k;
		int w=lower_bound(v+1,v+cnt+1,x)-v;
		if(w<=cnt&&w>=1&&v[w]==v[i]+k)nxt[i]=w;
		x=v[i]-k;
		w=lower_bound(v+1,v+cnt+1,x)-v;
		if(w<=cnt&&w>=1&&v[w]==v[i]-k)pre[i]=w;
	}
	for(int i=0;i<=n;i++)sum[i]=lower_bound(v+1,v+cnt+1,sum[i])-v;
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>q[i].l>>q[i].r;
		q[i].id=i;q[i].l--; 
	}
	sort(q+1,q+m+1,cmp);
	int L=0,R=-1;
	ll res=0;
	for(int i=1;i<=m;i++){
		while(R<q[i].r){
			++R;
			if(pre[sum[R]])res+=b[pre[sum[R]]];
			b[sum[R]]++;
		}
		while(R>q[i].r){
			b[sum[R]]--;
			if(pre[sum[R]])res-=b[pre[sum[R]]];
			--R;
		}
		while(L<q[i].l){
			b[sum[L]]--;
			if(nxt[sum[L]])res-=b[nxt[sum[L]]];
			++L;
		}
		while(L>q[i].l){
			--L;
			if(nxt[sum[L]])res+=b[nxt[sum[L]]];
			b[sum[L]]++;
		}
		ans[q[i].id]=res;
	}
	for(int i=1;i<=m;i++)
                cout<<ans[i]<<endl;
}