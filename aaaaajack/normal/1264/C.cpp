#include<bits/stdc++.h>
#define N 200100
using namespace std;
const int Q=998244353;
typedef long long ll;
inline ll inv(ll x){
	int y=Q-2;
	ll r=1;
	while(y){
		if(y&1) r=r*x%Q;
		y>>=1;
		x=x*x%Q;
	}
	return r;
}
struct seg{
	seg(){}
	seg(ll beg,ll nxt,ll cst):beg(beg),nxt(nxt),cst(cst){}
	ll beg;
	ll nxt;
	ll cst;
};
seg merge(seg a,seg b){
	seg tmp;
	tmp.cst=(a.cst+a.nxt*b.cst)%Q;
	tmp.beg=(a.beg+a.nxt*b.beg)%Q;
	tmp.nxt=a.nxt*b.nxt%Q;
	return tmp;
}
seg tr[N*2];
void build(int n){
	for(int i=n-1;i>=1;i--){
		tr[i]=merge(tr[i*2],tr[i*2+1]);
	}
}
ll qry(int l,int r,int n){
	int nl=n+l,nr=n+r;
	vector<seg> left,right;
	while(nl<nr){
		if(nl&1) left.push_back(tr[nl++]);
		if(nr&1) right.push_back(tr[--nr]);
		nl>>=1;
		nr>>=1;
	}
	seg st(0,1,0);
	reverse(right.begin(),right.end());
	for(auto x: left) st=merge(st,x);
	for(auto x: right) st=merge(st,x);
	return st.cst*inv((Q+1-st.beg)%Q)%Q;
}
int main(){
	int n,q;
	int x,y;
	ll i100=inv(100);
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		tr[n+i].beg=(100-x)*i100%Q;
		tr[n+i].nxt=x*i100%Q;
		tr[n+i].cst=1;
	}
	set<int> now;
	now.insert(0);
	now.insert(n);
	build(n);
	ll cur=qry(0,n,n);
	while(q--){
		scanf("%d",&y);
		y--;
		bool flag=false;
		if(now.count(y)){
			flag=true;
		}
		else now.insert(y);
		auto it=now.find(y);
		auto nxt=it,pre=it;
		++nxt;
		--pre;
		ll sp=qry(*pre,y,n),sn=qry(y,*nxt,n),spn=qry(*pre,*nxt,n);
		if(flag){
			cur=(cur+Q+Q-sp-sn+spn)%Q;
			now.erase(y);
		}
		else{
			cur=(cur+Q-spn+sp+sn)%Q;
		}
		printf("%lld\n",cur);
	}
	return 0;
}