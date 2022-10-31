#include<cstdio>
#include<vector>
#include<algorithm>
#define Q 1000000007
#define N 1001000
#define M 200100
using namespace std;
vector<int> pos[N];
vector<int> pf[N];
int lpf[N],prm[N],inv[N],pcnt;
int ans[M],a[M],f[M];
bool notp[N];
struct qry{
	int l,r,id;
	bool operator<(const qry& o)const{return l<o.l;}
}qq[M];
int cal_inv(int x){
	int y=Q-2,r=1;
	while(y){
		if(y&1) r=1LL*r*x%Q;
		x=1LL*x*x%Q;
		y>>=1;
	}
	return r;
}
void upd(int x,int v){
	while(x<M){
		f[x]=1LL*v*f[x]%Q;
		x+=x&-x;
	}
}
int mul(int x){
	int r=1;
	while(x){
		r=1LL*r*f[x]%Q;
		x-=x&-x;
	}
	return r;
}
int main(){
	for(int i=2;i<N;i++){
		if(!notp[i]) prm[pcnt++]=i,lpf[i]=i;
		for(int j=0;j<pcnt&&i*prm[j]<N;j++){
			notp[i*prm[j]]=true;
			lpf[i*prm[j]]=prm[j];
			if(i%prm[j]==0) break;
		}
	}
	for(int i=1;i<N;i++){
		inv[i]=cal_inv(i);
	}
	for(int i=1;i<M;i++) f[i]=1;
	int n,q,now=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		upd(i,a[i]);
	}
	for(int i=n;i>=1;i--){
		while(a[i]>1){
			int p=lpf[a[i]];
			pf[i].push_back(p);
			pos[p].push_back(i);
			while(a[i]%p==0) a[i]/=p;
		}
	}
	for(int i=0;i<pcnt;i++){
		if(!pos[prm[i]].empty()){
			upd(pos[prm[i]].back(),1LL*inv[prm[i]]*(prm[i]-1)%Q);
		}
	}
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		scanf("%d%d",&qq[i].l,&qq[i].r);
		qq[i].id=i;
	}
	sort(qq,qq+q);
	for(int i=0;i<q;i++){
		while(now<qq[i].l){
			upd(now,inv[f[now]]);
			for(int j=0;j<pf[now].size();j++){
				int p=pf[now][j];
				pos[p].pop_back();
				if(!pos[p].empty()){
					upd(pos[p].back(),1LL*inv[p]*(p-1)%Q);
				}
			}
			now++;
		}
		ans[qq[i].id]=mul(qq[i].r);
	}
	for(int i=0;i<q;i++) printf("%d\n",ans[i]);
	return 0;
}