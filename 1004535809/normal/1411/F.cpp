#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define mt make_tuple
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
namespace fastio{
	#define FILE_SIZE 1<<23
	char rbuf[FILE_SIZE],*p1=rbuf,*p2=rbuf,wbuf[FILE_SIZE],*p3=wbuf;
	inline char getc(){return p1==p2&&(p2=(p1=rbuf)+fread(rbuf,1,FILE_SIZE,stdin),p1==p2)?-1:*p1++;}
	inline void putc(char x){(*p3++=x);}
	template<typename T> void read(T &x){
		x=0;char c=getchar();T neg=0;
		while(!isdigit(c)) neg|=!(c^'-'),c=getchar();
		while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
		if(neg) x=(~x)+1;
	}
	template<typename T> void recursive_print(T x){return (!x)?void():(recursive_print(x/10),putc(x%10^48),void());}
	template<typename T> void print(T x){(!x)&&(putc('0'),0);(x<0)&&(putc('-'),x=~x+1);recursive_print(x);}
	template<typename T> void print(T x,char c){print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=1e6;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;
int qpow(int x,int e){
	int ret=1;
	for(;e;e>>=1,x=1ll*x*x%MOD) if(e&1) ret=1ll*ret*x%MOD;
	return ret;
}
int n,p[MAXN+5],vis[MAXN+5];
int ccnt=0,cyc[MAXN+5];
void solve(){
	for(int i=1;i<=ccnt;i++) cyc[i]=0;ccnt=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&p[i]),vis[i]=0;
	for(int i=1;i<=n;i++) if(!vis[i]){
		int cur=i;ccnt++;
		while(!vis[cur]) cyc[ccnt]++,vis[cur]=1,cur=p[cur];
	}
	if(n==1) return puts("1 0"),void();
	if(n%3==0){
		printf("%d ",qpow(3,n/3));int sum=0,cnt[3]={0};
		for(int i=1;i<=ccnt;i++) sum+=(cyc[i]-1)/3,cnt[cyc[i]%3]++;
		sum+=min(cnt[1],cnt[2]);
		if(cnt[1]>cnt[2]) sum+=(cnt[1]-cnt[2])/3*2;
		else sum+=cnt[2]-cnt[1];
		printf("%d\n",sum);
	} else if(n%3==2){
		printf("%d ",qpow(3,(n-2)/3)*2%MOD);
		int sum=0,cnt[3]={0};
		for(int i=1;i<=ccnt;i++) sum+=(cyc[i]-1)/3,cnt[cyc[i]%3]++;
		if(cnt[2]) cnt[2]--;
		else if(cnt[1]) cnt[1]-=2,sum++;
		else assert(0);
		sum+=min(cnt[1],cnt[2]);
		if(cnt[1]>cnt[2]) sum+=(cnt[1]-cnt[2])/3*2;
		else sum+=cnt[2]-cnt[1];
		printf("%d\n",sum);
	} else {
		printf("%d ",qpow(3,(n-4)/3)*4ll%MOD);
		int sum=0,res=INF;vector<int> ps;
		int pos1=-1,pos2=-1;
		function<int()> calc=[&](){
			int cnt[3]={0},sum=0;
			for(int i=1;i<=ccnt;i++) if(cyc[i]) sum+=(cyc[i]-1)/3,cnt[cyc[i]%3]++;
			sum+=min(cnt[1],cnt[2]);
			if(cnt[1]>cnt[2]) sum+=(cnt[1]-cnt[2])/3*2;
			else sum+=cnt[2]-cnt[1];
			return sum;
		};
		for(int i=1;i<=ccnt;i++) if(cyc[i]>=4&&cyc[i]%3==1){
			cyc[i]-=4;chkmin(res,calc()+(!!cyc[i]));
			cyc[i]+=4;
		}
		for(int i=1;i<=ccnt;i++) if(cyc[i]==1) ps.pb(i);
		for(int i=1;i<=ccnt;i++){
			if(cyc[i]%3==2&&ps.size()>=2){
				cyc[i]-=2;cyc[ps[0]]=cyc[ps[1]]=0;
				chkmin(res,calc()+(!!cyc[i])+1);
				cyc[i]+=2;cyc[ps[0]]=cyc[ps[1]]=1;
				break;
			}
		}
		for(int i=1;i<=ccnt;i++){
			if(cyc[i]==1) pos1=i;
			if(cyc[i]%3==0) pos2=i;
		}
		if(~pos1&&~pos2){
			cyc[pos1]=0;cyc[pos2]-=3;
			chkmin(res,calc()+(!!cyc[pos2])+1);
			cyc[pos1]=1;cyc[pos2]+=3;
		}
		pos1=-1,pos2=-1;
		for(int i=1;i<=ccnt;i++){
			if(cyc[i]%3==2){
				if(pos1==-1) pos1=i;
				else if(pos2==-1) pos2=i;
			}
		}
		if(~pos1&&~pos2){
			int sum=(cyc[pos1]>2)+(cyc[pos2]>2);
			cyc[pos1]-=2;cyc[pos2]-=2;
			chkmin(res,sum+calc());
			cyc[pos1]+=2;cyc[pos2]+=2;
		}
		if(ps.size()>=4){
			cyc[ps[0]]=cyc[ps[1]]=cyc[ps[2]]=cyc[ps[3]]=0;
			chkmin(res,2+calc());
		} printf("%d\n",res);
	}
}
int main(){
	int qu;scanf("%d",&qu);
	while(qu--) solve();
	return 0;
}