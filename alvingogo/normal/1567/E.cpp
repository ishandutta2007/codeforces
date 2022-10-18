#include <iostream>
#include <vector>
#define fastio cin.tie(0);ios_base::sync_with_stdio(0);

using namespace std;

struct st{
	long long lnd,rnd,sum=0;
	bool im=0;
};

int n;
long long k=0,ans=0;
vector<long long> vq;
vector<st> vs;

long long f(int k){
	return 1ll*k*(k+1)/2;
}
void calc(int v,int m){
	if(vs[2*v+1].im==1 && vs[2*v+2].im==1 && vq[m+1]>=vq[m]){
		vs[v].im=1;
		vs[v].lnd=vs[2*v+1].lnd+vs[2*v+2].lnd;
		vs[v].rnd=vs[2*v+1].lnd+vs[2*v+2].lnd;
		vs[v].sum=0;
		return;
	}
	if(vs[2*v+1].im==1 && vs[2*v+2].im==1){
		vs[v].lnd=vs[2*v+1].lnd;
		vs[v].rnd=vs[2*v+2].rnd;
		vs[v].im=0;
		vs[v].sum=0;
	}
	else{
		vs[v].im=0;
		if(vq[m+1]>=vq[m]){
			if(vs[2*v+1].im==1){
				vs[v].lnd=vs[2*v+1].lnd+vs[2*v+2].lnd;
				vs[v].rnd=vs[2*v+2].rnd;
				vs[v].sum=vs[2*v+2].sum;
			}
			else if(vs[2*v+2].im==1){
				vs[v].lnd=vs[2*v+1].lnd;
				vs[v].rnd=vs[2*v+1].rnd+vs[2*v+2].rnd;
				vs[v].sum=vs[2*v+1].sum;
			}
			else{
				vs[v].lnd=vs[2*v+1].lnd;
				vs[v].rnd=vs[2*v+2].rnd;
				vs[v].sum=vs[2*v+1].sum+vs[2*v+2].sum+f(vs[2*v+1].rnd+vs[2*v+2].lnd);
			}
		}
		else{
			vs[v].lnd=vs[2*v+1].lnd;
			vs[v].rnd=vs[2*v+2].rnd;
			if(vs[2*v+1].im==1){
				vs[v].sum=vs[2*v+2].sum+f(vs[2*v+2].lnd);
			}
			else if(vs[2*v+2].im==1){
				vs[v].sum=vs[2*v+1].sum+f(vs[2*v+1].rnd);
			}
			else{
				vs[v].sum=vs[2*v+1].sum+vs[2*v+2].sum+f(vs[2*v+1].rnd)+f(vs[2*v+2].lnd);
			}
		}
	}
}
void build(int l,int r,int v){
	if(l==r){
		vs[v].lnd=1;
		vs[v].rnd=1;
		vs[v].im=1;
		vs[v].sum=0;
		return;
	}
	int m=(l+r)/2;
	build(l,m,2*v+1);
	build(m+1,r,2*v+2);
	calc(v,m);
}
void update(int v,int l,int r,int x,int y){
	if(l==r){
		vq[x]=y;
		return;
	}
	int m=(l+r)/2;
	if(x<=m){
		update(2*v+1,l,m,x,y);
	}
	else{
		update(2*v+2,m+1,r,x,y);
	}
	calc(v,m);
}
void query(int l,int r,int v,int L,int R){
	if(l>R || L>r){
		return;
	}
	int m=(L+R)/2;
	if(l<=L && r>=R){
		if(vs[v].im==1){
			if(L>0 && vq[L-1]>vq[L]){
				ans+=f(k);
				k=R-L+1;
			}
			else{
				k+=R-L+1;
			}
		}
		else{
			if(L==0){
				ans+=vs[v].sum+f(vs[v].lnd);
			}
			else if(vq[L-1]>vq[L]){
				ans+=vs[v].sum+f(k)+f(vs[v].lnd);
			}
			else{
				ans+=vs[v].sum+f(k+vs[v].lnd);
			}
			k=vs[v].rnd;
		}
		return;
	}	
	query(l,r,2*v+1,L,m);
	query(l,r,2*v+2,m+1,R); 
}
int main(){
	fastio;
	int q;
	cin >> n >> q;
	vq.resize(n);
	vs.resize(4*n);
	for(int i=0;i<n;i++){
		cin >> vq[i];
	}
	build(0,n-1,0);
	int a,b,c;
	while(q--){
		cin >> a >> b >> c;
		if(a==1){
			b--;
			update(0,0,n-1,b,c);
		}
		else{
			ans=0;
			k=0;
			b--;
			c--;
			query(b,c,0,0,n-1);
			cout << ans+f(k) << "\n";
		}
	}
	return 0;
}