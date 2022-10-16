#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N=2e5+5;
const int M=450;

int n,t,a[N],b[N],c[N<<3];
ll ans[N],now;

struct query{
	int l,r,id;
	bool operator < (const query &v) const {
		return b[l]==b[v.l]?b[r]<b[v.r]:b[l]<b[v.l];
	}
}d[N];

void add(int id){
	ll v=++c[a[id]];
	now=now+(2*v-1)*a[id];
}

void del(int id){
	ll v=--c[a[id]];
	now=now-(2*v+1)*a[id];
}

int main() {
	cin>>n>>t;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=t;i++)cin>>d[i].l>>d[i].r,d[i].id=i,b[i]=i/M+1;
	sort(d+1,d+t+1);
	int l=1,r=0;
	for(int i=1;i<=t;i++){
		while(d[i].l<l)add(--l);
		while(l<d[i].l)del(l++);
		while(d[i].r<r)del(r--);
		while(r<d[i].r)add(++r);
		ans[d[i].id]=now;
	} for(int i=1;i<=t;i++)cout<<ans[i]<<endl;
	return 0;
}