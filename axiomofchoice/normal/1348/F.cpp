#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=200010; typedef long long ll; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef pair<int,int> pii;
struct seg{
	#define U(a,b) (a+b) //
	ll a0=0; //
	int n; ll a[1024*1024*4*2]; //2^kinn
	void init(int inn){ //
		for(n=1;n<inn;n<<=1);
		repeat(i,0,n)a[n+i]=0;
		repeat_back(i,1,n)up(i);
	}
	void up(int x){
		a[x]=U(a[x<<1],a[(x<<1)^1]);
	}
	void update(int x,ll k){ //xk
		a[x+=n]+=k; //
		while(x>>=1)up(x);
	}
	ll query(int l,int r){ //
		ll ans=a0;
		for(l+=n-1,r+=n+1;l^r^1;l>>=1,r>>=1){
			if(~l & 1)ans=U(ans,a[l^1]); //l^1l+1
			if(r & 1)ans=U(ans,a[r^1]); //r^1r-1
		}
		return ans;
	}
}tr;
struct node{
	int l,r,m,rawp,p;
}a[N];
struct op{bool operator()(const node &a,const node &b){return -a.r<-b.r;}};
priority_queue<node,vector<node>,op> q;
int n,ans[N],pos[N],r,rr;
void output(){
	repeat(i,0,n)cout<<ans[i]+1<<' ';
	cout<<endl;
}
void get_first_ans(){
	int ptr=0;
	repeat(i,0,n){
		while(ptr<n && a[ptr].l==i)
			q.push(a[ptr++]);
		a[q.top().p].m=i; ans[q.top().rawp]=i; pos[i]=q.top().p; q.pop();
	}
}
bool get_second_ans(){
	int ptr=0;
	repeat(i,0,n){
		int x=pos[i];
		while(ptr<n && a[ptr].l==i){
			tr.update(a[ptr].m,1);
			q.push(a[ptr++]);
		}
		while(!q.empty() && a[q.top().p].r<a[x].m){
			tr.update(a[q.top().p].m,-1);
			q.pop();
		}
		if(tr.query(a[x].l,a[x].r)>=2){
			r=x;
			#define inc(a,b,c) (a<=b && b<=c)
			repeat(j,0,n)
			if(j!=r)
			if(inc(a[j].l,a[r].m,a[j].r) && inc(a[r].l,a[j].m,a[r].r)){
				rr=j;
				return true;
			}
			cout<<"wcynb"; return false;
		}
	}
	return false;
}
signed main(){
	n=read(); tr.init(n+1);
	repeat(i,0,n){
		a[i].l=read()-1;
		a[i].r=read()-1;
		a[i].rawp=i;
	}
	sort(a,a+n,[](const node &a,const node &b){
		return a.l<b.l;
	});
	repeat(i,0,n)a[i].p=i;
	get_first_ans();
	if(get_second_ans()){
		cout<<"NO"<<endl;
		output();
		swap(ans[a[r].rawp],ans[a[rr].rawp]);
		output();
	}
	else{
		cout<<"YES"<<endl;
		output();
	}
	return 0;
}