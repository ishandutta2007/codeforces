#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;

struct seq{
	int l,r,id,st;
	bool operator < (const seq &v) const {
		return l!=v.l?l<v.l:r<v.r;
	}
};

int n,m,cnt,node,R[N<<1],ls[N<<6],rs[N<<6],val[N<<6];
set <seq> s;
char a;

void ins(int l,int r,int p,int &x){
	val[x=++node]=1;
	if(l==r)return void();
	int m=l+r>>1;
	if(p<=m)ins(l,m,p,ls[x]);
	else ins(m+1,r,p,rs[x]);
}

void spl(int x,int &y,int k){
	if(!x)return;
	y=++node;
	int v=val[ls[x]];
	if(v<k)spl(rs[x],rs[y],k-v);
	else swap(rs[x],rs[y]);
	if(v>k)spl(ls[x],ls[y],k);
	val[y]=val[x]-k,val[x]=k;
}

int merge(int x,int y){
	if(!x||!y)return x|y;
	ls[x]=merge(ls[x],ls[y]);
	rs[x]=merge(rs[x],rs[y]);
	return val[x]+=val[y],x;
}

string ans,cur;
void get(int l,int r,int x){
	if(l==r){
		for(int i=1;i<=val[x];i++)cur+='a'+l-1;
		return;
	}
	int m=l+r>>1;
	get(l,m,ls[x]),get(m+1,r,rs[x]); 
}

int main(){
	cin>>n>>m,cnt=n;
	for(int i=1;i<=n;i++)cin>>a,ins(1,26,a-'a'+1,R[i]),s.insert({i,i,i,0});
	for(int i=1;i<=m;i++){
		int op,l,r,id=++cnt; cin>>l>>r>>op,op^=1;
		auto p=--s.upper_bound({l,n+1,0,0}),tmp=p;
		seq t=*p;
		if(t.l<l){
			p++,s.erase(tmp);
			if(r<t.r){
				if(t.st==0){
					spl(R[t.id],R[id],l-t.l);
					spl(R[id],R[++cnt],r-l+1);
				}
				else{
					spl(R[t.id],R[id],t.r-l+1),swap(R[t.id],R[id]);
					spl(R[id],R[++cnt],t.r-r),swap(R[id],R[cnt]);
				}
				s.insert({t.l,l-1,t.id,t.st});
				s.insert({r+1,t.r,cnt,t.st});
				s.insert({l,r,id,op});
				continue;
			}
			if(t.st==0)spl(R[t.id],R[id],l-t.l);
			else spl(R[t.id],R[id],t.r-l+1),swap(R[t.id],R[cnt]);
			s.insert({t.l,l-1,t.id,t.st});
		}
		for(tmp=p;p!=s.end()&&(*p).r<=r;tmp=p)
			R[id]=merge(R[id],R[(*p).id]),p++,s.erase(tmp);
		if(p!=s.end()&&(*p).l<=r){
			t=*p,s.erase(p);
			if(t.st==0)spl(R[t.id],R[++cnt],r-t.l+1),swap(R[t.id],R[cnt]);
			else spl(R[t.id],R[++cnt],t.r-r);
			R[id]=merge(R[id],R[cnt]),s.insert({r+1,t.r,t.id,t.st});
		}
		s.insert({l,r,id,op});
	}
	for(auto it:s){
		cur="",get(1,26,R[it.id]);
		if(it.st)reverse(cur.begin(),cur.end());
		ans+=cur;
	}
	cout<<ans<<endl;
	return 0;
}
/*
 ++ 
*/