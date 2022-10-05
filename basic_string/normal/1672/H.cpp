#include<bits/stdc++.h>
using namespace std;
enum{N=200009};
char s[N];
struct T{
	bool l,r;
	int s,c0,c1;
}t[N*4];
int u,v;
T mg(const T&a,const T&b){
	return{a.l,b.r,a.s+b.s-(a.r==b.l),a.c0+b.c0,a.c1+b.c1};
}
void bd(int k,int l,int r){
	if(l==r){
		t[k].s=1,t[k].l=t[k].r=(s[l]=='1');
	if(s[l]=='1')t[k].c1=1;else t[k].c0=1;
		return;
	}
	int m=l+r>>1;
	bd(k*2,l,m);
	bd(k*2+1,m+1,r);t[k]=mg(t[k*2],t[k*2+1]);
}
T qry(int k,int l,int r){
	if(u<=l&&r<=v)return t[k];
	int m=l+r>>1;
	if(u<=m&&m<v)return mg(qry(k*2,l,m),qry(k*2+1,m+1,r));
	if(u<=m)return qry(k*2,l,m);
	return qry(k*2+1,m+1,r);
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int n,q;
	cin>>n>>q>>s+1;
	bd(1,1,n);
	while(q--){
		cin>>u>>v;
		auto o=qry(1,1,n);
		int ct=o.s,len=v-u+1;
		int c0=o.c0-ct/2,c1=o.c1-ct/2;
		if(ct&1){
			if(s[u]=='1')--c1;
			else --c0;
		}
		cout<<max(c0,c1)+1<<'\n';
	//	cout<<(len-ct+1)/2+1<<'\n';
	}
}
/*
0000111111110000000011111100 28 23 5 13
len=28
ct=5
ans=(len-ct+1)/2+1*/