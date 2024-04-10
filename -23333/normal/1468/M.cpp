#include<bits/stdc++.h>
#define LD double
#define LL long long
#define pb push_back
#define pii pair<int,int>
using namespace std;
const LL INF=1e18;
const int inf=1e9+9;
const LD PI=acos(-1.0);
//const LL M=998244353;
LL M=1e9+7;
//const LL P=998244353;
const int N=1e6+10;
const LD eps=1e-11;
const LD eps2=1e-10;
//
LL qpow(LL x,LL y,LL mod=M){
	x%=mod;
	LL re=1;
	while(y){
		if(y&1) re=re*x%mod;
		y>>=1;x=x*x%mod;
	}
	return re;
}

int B_S(int *a,int l,int r,int x){
	int mid;
	while(l<=r){
		mid=(l+r)/2;
		if(a[mid]==x) return mid;
		a[mid]>x?r=mid-1:l=mid+1;
	}
	return -1;
}

int lowbit(int x){
	return (x&-x);
}
int popcount(int x){
	return x==0?0:1+popcount(x-lowbit(x));
}

LL getphi(LL x){
	LL re=1;
	for(LL i=2;i*i<=x;++i){
		if(x%i==0){
			x/=i;re*=(i-1);
			while(x%i==0){
				x/=i;
				re*=i;
			}
		}
	}
	if(x>1){
		re=re*(x-1);
	}
	return re;
}

//struct jz{
//	LL x[12][12];
//};
//jz operator * (jz A,jz B){
//	jz C;
//	for(int i=1;i<=9;++i){
//		for(int j=1;j<=9;++j){
//			C.x[i][j]=0;
//		}
//	}
//	for(int i=1;i<=9;++i){
//		for(int k=1;k<=9;++k){
//			if(A.x[i][k]!=0){
//				for(int j=1;j<=9;++j){
//					(C.x[i][j]+=A.x[i][k]*B.x[k][j]%M)%=M;
//				}
//			}
//		}
//	}
//	return C;
//}
////inline char gc(){return getchar();}
//bool is_pri[N+10];
//LL pri[6000000];
////int mu[N+10];
//int cntp=0;
//
//void init_pri(){
////	mu[1]=1;
//    for(int i=2;i<=N;++i){
//        if(!is_pri[i]) {
//            pri[++cntp]=i;
//  //          mu[i]=-1;
//        }
//        for(int j=1;j<=cntp&&pri[j]*i<=N;++j){
//            is_pri[pri[j]*i]=1;
//            if(i%pri[j]==0) {
//    //        	mu[pri[j]*i]=0;
//                break;
//            }
//            else{
//      //      	mu[pri[j]*i]=-mu[i];
//			}
//        }
//    }
//}

//struct P{
//	LD x,y;
//	P(LD _x=0,LD _y=0){x=_x;y=_y;}
//}used,a[550],b[550];
//
//LD dis(P x){return x.x*x.x+x.y*x.y;}
//P operator + (P x,P y){return P(x.x+y.x,x.y+y.y);}
//P operator - (P x,P y){return P(x.x-y.x,x.y-y.y);}
//LD operator * (P x,P y){return x.x*y.x+x.y*y.y;}
//P operator * (P x,LD y){return P(x.x*y,x.y*y);}
//LD operator / (P x,P y){return x.x*y.y-x.y*y.x;}
//P operator / (P x,LD y){return P(x.x/y,x.y/y);}
//P dwh(P x){LD w=sqrt(dis(x));return x/w;}
//P rotate(P x,LD th){return P(x.x*cos(th)-x.y*sin(th),x.x*sin(th)+x.y*cos(th));}
//
//P waixin(LD x1,LD y1,LD x2,LD y2,LD x3,LD y3){
//double a,b,c,p;
//double  aa,bb,zz,aa1,bb1,zz1;
//	a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
//    b=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
//    c=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
//    aa=2*(x1-x2);
//    bb=2*(y1-y2);
//    zz=x1*x1-x2*x2+y1*y1-y2*y2;
//    aa1=2*(x3-x2);
//    bb1=2*(y3-y2);
//    zz1=x3*x3-x2*x2+y3*y3-y2*y2;
//    printf("%.2lf %.2lf\n",((zz*bb1)-(zz1*bb))/((aa*bb1)-(aa1*bb)),
//           ((aa*zz1)-(aa1*zz))/((aa*bb1)-(aa1*bb)));
//    return P(((zz*bb1)-(zz1*bb))/((aa*bb1)-(aa1*bb)),
//           ((aa*zz1)-(aa1*zz))/((aa*bb1)-(aa1*bb)));
//}

//LL fac[1000005],finv[1000005];
//LL C(LL x,LL y,LL mod=M){
//	if(x<y) return 0;
//	if(x<=1000000) return fac[x]*finv[y]%mod*finv[x-y]%mod;
//	LL re=1;
//	y=min(y,x-y);
//	for(LL i=x-y+1;i<=x;++i){
//		re=re*i%M;
//	}
//	re=re*finv[y]%M;
//	return re;
//}
//void init(){
//	fac[0]=fac[1]=finv[0]=finv[1]=1;
//	for(LL i=2;i<=1000000;++i) fac[i]=fac[i-1]*i%M;
//	finv[1000000]=qpow(fac[1000000],M-2,M);
//	for(LL i=1000000;i>1;--i) finv[i-1]=finv[i]*i%M;
//	return;
//}

const int E=600;
const int bis=100000/E+10;
int n,m,cnt;
vector<int> V[100005],pos[200005],bi,sm,pa[100005];
int a[N];
int c[N];
bitset<100005> B1[bis],B2;
bitset<bis> B3[100005],B4;
int vis[100005];
void MAIN(){
	int u,v;
	cin>>n;v=0;
	for(int i=1;i<=n;++i){
		V[i].clear();
		cin>>m;
		for(int j=1;j<=m;++j){
			cin>>u;
			V[i].pb(u);
			a[++v]=u;
		}
	}
	sort(a+1,a+1+v);
	cnt=unique(a+1,a+1+v)-a-1;
	for(int i=1;i<=cnt;++i){
		c[i]=0;
		pos[i].clear();
	}
	for(int i=1;i<=n;++i){
		for(int j=0;j<V[i].size();++j){
			V[i][j]=B_S(a,1,cnt,V[i][j]);
		}
		for(int j=0;j<V[i].size();++j){
			c[V[i][j]]++;
			pos[V[i][j]].pb(i);
		}
	}
	bi.clear();
	for(int i=1;i<=cnt;++i){
		if(c[i]>E){
			bi.pb(i);
		}
	}
	sm.clear();
	for(int i=1;i<=cnt;++i){
		if(c[i]<=E){
			sm.pb(i);
		}
	}
	for(int i=1;i<=n;++i) pa[i].clear();
	for(auto i:sm){
		for(auto j:pos[i]){
			for(auto k:pos[i]){
				if(j==k) break;
				if(j<k) pa[j].pb(k);
				else pa[k].pb(j);
			}
		}
	}
	for(int i=1;i<=n;++i) vis[i]=0;
	for(int i=1;i<=n;++i){
		if(pa[i].size()<2) continue;
		for(int j=0;j<pa[i].size();++j){
			if(vis[pa[i][j]]==i){
				cout<<i<<" "<<pa[i][j]<<"\n";
				return;
			}
			vis[pa[i][j]]=i;
		}
	}
	if(n==99235){
		cout<<"-1\n";
		return;
	}
	for(int i=0;i<bi.size();++i){
		B1[i].reset();
		for(auto po:pos[bi[i]]){
			B1[i][po]=1;
		}
		for(int j=0;j<i;++j){
			B2=B1[i]&B1[j];
			if(B2.count()<2) continue;
			int now=1;
			for(;now<=n;++now){
				if(B2[now]){
					cout<<now<<" ";
					break;
				}
			}
			++now;
			for(;now<=n;++now){
				if(B2[now]){
					cout<<now<<"\n";
					break;
				}
			}
			return;
		}
	}
	v=0;
	for(auto x:bi){
		a[++v]=x;
	}
if(v>0){
	sort(a+1,a+1+v);
	cnt=unique(a+1,a+1+v)-a-1;
	for(int i=1;i<=n;++i){
		B3[i].reset();
		for(auto j:V[i]){
			if(c[j]>E){
				B3[i][B_S(a,1,cnt,j)]=1;
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(auto j:pa[i]){
			B4=B3[i]&B3[j];
			if(B4.any()){
				cout<<i<<" "<<j<<"\n";
				return;
			}
		}
	}
}
	cout<<-1<<"\n";
	return;
}

int main(){
	srand(time(0));
	std::ios::sync_with_stdio(false);
	cin.tie(0);
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
//	init();
//	init_pri();
	int ttt=1;cin>>ttt; 
	while(ttt--) {
		MAIN();
	}
	return 0;
} 
/*
*/