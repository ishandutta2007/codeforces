#include <bits/stdc++.h>
using namespace std;
using ll=long long; //using lll=__int128;
using pii=pair<int,int>;
#define repeat(i,a,b) for(int i=(a),iE=(b);i<iE;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,iE=(a);i>=iE;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define N 1010
#define inf 1e9
#define qwq {cout<<"qwq"<<endl;}
//#define int ll
const int mod=1000000007;
#define zero 0
#define fun(x,y) min(x,y)
struct ST{//build(1,1,n) update(1,1,n,?,?,?) query(1,1,n,?,?)
	int a[4000010],lazy[4000010];//
	void build(int n,int l,int r){
		int lc=n*2,rc=n*2+1,m=(l+r)/2;
		lazy[n]=zero;
		if(l==r){
			a[n]=zero;
			return;
		}
		build(lc,l,m);
		build(rc,m+1,r);
		a[n]=fun(a[lc],a[rc]);
	}
	void down(int n,int l,int r){
		int lc=n*2,rc=n*2+1,m=(l+r)/2;
		if(l<r){
			lazy[lc]+=lazy[n];
			lazy[rc]+=lazy[n];
		}
		a[n]+=lazy[n];
		lazy[n]=zero;
	}
	void update(int n,int l,int r,int x,int y,ll num){
		int lc=n*2,rc=n*2+1,m=(l+r)/2;
		x=max(x,l); y=min(y,r); if(x>y){down(n,l,r);return;}//!!
		if(x==l && y==r){
			lazy[n]+=num;
			down(n,l,r);
			return;
		}
		down(n,l,r);
		update(lc,l,m,x,y,num);
		update(rc,m+1,r,x,y,num);
		a[n]=fun(a[lc],a[rc]);
	}
	ll query(int n,int l,int r,int x,int y){
		int lc=n*2,rc=n*2+1,m=(l+r)/2;
		x=max(x,l); y=min(y,r); if(x>y)return 1e9;
		down(n,l,r);
		if(x==l && y==r)
			return a[n];
		return fun(query(lc,l,m,x,y),query(rc,m+1,r,x,y));
	}
}t1;
#undef fun
#define fun(x,y) max(x,y)
struct ST2{//build(1,1,n) update(1,1,n,?,?,?) query(1,1,n,?,?)
	int a[4000010],lazy[4000010];//
	void build(int n,int l,int r){
		int lc=n*2,rc=n*2+1,m=(l+r)/2;
		lazy[n]=zero;
		if(l==r){
			a[n]=zero;
			return;
		}
		build(lc,l,m);
		build(rc,m+1,r);
		a[n]=fun(a[lc],a[rc]);
	}
	void down(int n,int l,int r){
		int lc=n*2,rc=n*2+1,m=(l+r)/2;
		if(l<r){
			lazy[lc]+=lazy[n];
			lazy[rc]+=lazy[n];
		}
		a[n]+=lazy[n];
		lazy[n]=zero;
	}
	void update(int n,int l,int r,int x,int y,ll num){
		int lc=n*2,rc=n*2+1,m=(l+r)/2;
		x=max(x,l); y=min(y,r); if(x>y){down(n,l,r);return;}//!!
		if(x==l && y==r){
			lazy[n]+=num;
			down(n,l,r);
			return;
		}
		down(n,l,r);
		update(lc,l,m,x,y,num);
		update(rc,m+1,r,x,y,num);
		a[n]=fun(a[lc],a[rc]);
	}
	ll query(int n,int l,int r,int x,int y){
		int lc=n*2,rc=n*2+1,m=(l+r)/2;
		x=max(x,l); y=min(y,r); if(x>y)return -1e9;
		down(n,l,r);
		if(x==l && y==r)
			return a[n];
		return fun(query(lc,l,m,x,y),query(rc,m+1,r,x,y));
	}
}t2;
#undef fun
int n;
string s;
int ss[1000010],sum=0;
void kill(int p){
	if(ss[p]==1){
		sum--;
		t1.update(1,1,n,p,n,-1);
		t2.update(1,1,n,p,n,-1);
	}
	else if(ss[p]==-1){
		sum++;
		t1.update(1,1,n,p,n,1);
		t2.update(1,1,n,p,n,1);
	}
	ss[p]=0;
}
signed main(){
	//ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	cin>>s;
	t1.build(1,1,n);
	t2.build(1,1,n);
	int p=1,flag=1;
	repeat(i,0,n)
	if(flag){
		if(s[i]=='('){
			if(ss[p]==1);
			else if(ss[p]==-1){
				sum+=2;
				t1.update(1,1,n,p,n,2);
				t2.update(1,1,n,p,n,2);
			}
			else{
				sum++;
				t1.update(1,1,n,p,n,1);
				t2.update(1,1,n,p,n,1);
			}
			ss[p]=1;
		}
		else if(s[i]==')'){
			if(ss[p]==-1);
			else if(ss[p]==1){
				sum-=2;
				t1.update(1,1,n,p,n,-2);
				t2.update(1,1,n,p,n,-2);
			}
			else{
				sum--;
				t1.update(1,1,n,p,n,-1);
				t2.update(1,1,n,p,n,-1);
			}
			ss[p]=-1;
		}
		else if(s[i]=='L'){
			p--;
			p=max(p,1);
		}
		else if(s[i]=='R'){
			p++;
		}
		else{
			kill(p);
		}
		if(!flag || sum!=0 || t1.query(1,1,n,1,n)<0)
			cout<<-1<<' ';
		else
			cout<<t2.query(1,1,n,1,n)<<' ';
		/*
		cout<<endl;
		repeat(i,1,n+1)cout<<t2.query(1,1,n,i,i)<<' ';
		cout<<endl;
		repeat(i,1,n+1)cout<<ss[i]<<' ';
		cout<<endl;
		cout<<t1.query(1,1,n,1,n)<<' '<<t2.query(1,1,n,1,n)<<endl;
		*/
	}
	else{
		cout<<-1<<' ';
	}
	cout<<endl;
	return 0;
}