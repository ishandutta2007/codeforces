#include<bits/stdc++.h>

using namespace std;

struct seg{
	int l,r;
	bool operator<(const seg&rhs)const{
		return l<rhs.l;
	}
};

const int N=200005,mo=998244353;
set<seg>s[N];
int n,q,o,l,r,x,i;

struct node{
	int l,r,m,ad,mu,sum;
}t[N<<2];

void build(int i,int l,int r){
	t[i].l=l,t[i].r=r;
	t[i].m=(l+r)>>1;
	t[i].mu=1;
	if(l==r){
		return;
	}
	build(i<<1,l,t[i].m);build(i<<1|1,t[i].m+1,r);
}

inline void pushi(int i,int x,int y){
	t[i].sum=(1ll*t[i].sum*x+1ll*y*(t[i].r-t[i].l+1))%mo;
	t[i].ad=(1ll*t[i].ad*x+y)%mo;
	t[i].mu=1ll*t[i].mu*x%mo;
}

inline void pushdown(int i){
	if(t[i].ad>0 || t[i].mu!=1){
		pushi(i<<1,t[i].mu,t[i].ad);
		pushi(i<<1|1,t[i].mu,t[i].ad);
		t[i].ad=0,t[i].mu=1;
	}
}

int query(int i,int x,int y){
	if(t[i].l==x && t[i].r==y)return t[i].sum;
	pushdown(i);
	if(x>t[i].m)return query(i<<1|1,x,y);
		else if(y<=t[i].m)return query(i<<1,x,y);
				else return (query(i<<1,x,t[i].m)+query(i<<1|1,t[i].m+1,y))%mo;
}

void mdy(int i,int x,int y,int a,int b){
	if(t[i].l==x && t[i].r==y){
		pushi(i,a,b);
		return;
	}
	pushdown(i);
	if(x>t[i].m)mdy(i<<1|1,x,y,a,b);
		else if(y<=t[i].m)mdy(i<<1,x,y,a,b);
				else mdy(i<<1,x,t[i].m,a,b),mdy(i<<1|1,t[i].m+1,y,a,b);
	t[i].sum=(t[i<<1].sum+t[i<<1|1].sum)%mo;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>q;
	build(1,1,n);
	while(q--){
		cin>>o>>l>>r;
		if(o==1){
			cin>>x;
			int u=l,v=r,lst;
			set<seg>::iterator it=s[x].upper_bound((seg){l,l});
			if(it!=s[x].begin()){
				--it;
				if(it->r>=r){
					mdy(1,l,r,2,0);
					continue;
				}
				if(it->r>=l-1){
					u=it->l;
					if(it->r>=l)mdy(1,l,it->r,2,0),lst=it->r+1;
						else lst=l;
					s[x].erase(it++);
				}else lst=l,++it;
			}else lst=l;
			for(;it!=s[x].end() && it->l<=r;){
				if(it->l>lst)mdy(1,lst,it->l-1,1,1);
				if(it->r<=r){
					mdy(1,it->l,it->r,2,0);
					lst=it->r+1;
				}else mdy(1,it->l,r,2,0),lst=r+1,v=it->r;
				s[x].erase(it++);
			}
			if(lst<=r)mdy(1,lst,r,1,1);
			if(it!=s[x].end()){
				if(it->l==r+1)v=it->r,s[x].erase(it);
			}
			s[x].insert((seg){u,v});
		}else cout<<query(1,l,r)<<'\n';
	}
}