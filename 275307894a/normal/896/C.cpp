#include <vector>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#define I inline
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define re register
#define ll long long
#define db double
#define N 100000
#define M 21000
#define mod 1000000007
#define eps (1e-7)
#define U unsigned int
#define IT set<ques>::iterator
using namespace std;
int n,m,op,l,r,Sh;ll Ans,Seed,res,x,p,Vmax;
struct ques{int l,r;mutable ll w;bool operator <(const ques &s)const{return l<s.l;}}tmp;set<ques> G;IT now,tot;
struct yyy{int l;ll w;}S[N+5];I bool cmp(yyy x,yyy y){return x.w<y.w;}
I ll Rand(){res=Seed;return Seed=(Seed*7+13)%mod,res;} 
I void swap(int &x,int &y){x^=y^=x^=y;}
I void split(int x){now=G.lower_bound((ques){x+1,0,0});now--;tmp=*now;G.erase(now);G.insert((ques){x,tmp.r,tmp.w});if(tmp.l^x) G.insert((ques){tmp.l,x-1,tmp.w});}
I ll mpow(ll x,int y){ll Ans=1;x%=p;while(y) (y&1)&&(Ans=Ans*x%p),y>>=1,x=x*x%p;return Ans;}
int main(){
//	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	re int i;scanf("%d%d%lld%lld",&n,&m,&Seed,&Vmax);for(i=1;i<=n;i++) G.insert((ques){i,i,Rand()%Vmax+1});
	while(m--){
		op=Rand()%4+1;l=Rand()%n+1;r=Rand()%n+1;if(l>r) swap(l,r);x=(op==3?Rand()%(r-l+1):Rand()%Vmax)+1;if(op==4) p=Rand()%Vmax+1;
		split(l);r!=n&&(split(r+1),0);/*printf("%d %d %d %d %d\n",op,l,r,x,p);*/now=G.lower_bound((ques){l,0,0});tot=G.lower_bound((ques){r+1,0,0});
		if(op==1){while(now!=tot) now->w+=x,now++;}
		else if(op==2){G.erase(now,tot);G.insert((ques){l,r,x});}
		else if(op==3){
			Sh=0;while(now!=tot) tmp=*now,S[++Sh]=(yyy){tmp.r-tmp.l+1,tmp.w},now++;sort(S+1,S+Sh+1,cmp);
			for(i=1;i<=Sh;i++) {x-=S[i].l;if(x<=0){printf("%lld\n",S[i].w);break;}}
		}
		else{Ans=0;while(now!=tot) tmp=*now,Ans+=(ll)(tmp.r-tmp.l+1)*mpow(tmp.w,x)%p,now++;printf("%lld\n",Ans%p);}
	}
}