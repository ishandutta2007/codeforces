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
const int MAXN=1e5;
int n,x,y,a[MAXN+5],cnt[MAXN+5],res[MAXN+5],ord[MAXN+5];
queue<int> q[MAXN+5],tq[MAXN+5];
void solve(){
	scanf("%d%d%d",&n,&x,&y);
	for(int i=1;i<=n+1;i++){
		cnt[i]=0;res[i]=0;
		while(!q[i].empty()) q[i].pop();
	}
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),cnt[a[i]]++,q[a[i]].push(i);
	int nt=0;for(int i=1;i<=n+1;i++) if(!cnt[i]) nt=i;
	multiset<pii> st;
	for(int i=1;i<=n+1;i++) if(cnt[i]) st.insert(mp(cnt[i],i));
	for(int i=1;i<=x;i++){
		pii p=*st.rbegin();st.erase(st.find(p));
		int c=p.se,id=q[c].front();q[c].pop();
		res[id]=c;p.fi--;if(p.fi) st.insert(p);
	} int sum=0,mx=0;
	for(int i=1;i<=n+1;i++) if(q[i].size()>mx) mx=q[i].size();
	for(int i=1;i<=n+1;i++) ord[i]=i;
	if((n-x-mx)+(n-y)<mx) puts("NO");
	else{
		puts("YES");
		sort(ord+1,ord+n+2,[&](int x,int y){return q[x].size()>q[y].size();});
		for(int i=1;i<=n+1;i++) tq[i]=q[i];
		int nd=n-y;
		for(int i=1;i<=n+1;i++){
			int x=ord[i];
			while(nd&&!q[x].empty()){
				int id=q[x].front();q[x].pop();
				res[id]=nt;nd--;
			}
		}
		int x=ord[1],cur=n+1;
		while(!q[x].empty()){
			while(!tq[ord[cur]].empty()&&!q[x].empty()){
				int P=tq[ord[cur]].front();tq[ord[cur]].pop();
				int Q=q[x].front();q[x].pop();res[Q]=ord[cur];
			} cur--;
		}
		cur=0;vector<int> seq;
		for(int i=1;i<=n+1;i++){
			int x=ord[i];
			while(!tq[x].empty()){
				int y=tq[x].front();tq[x].pop();
				seq.pb(x);
			}
		} //printf("%d\n",seq.size());
		for(int i=2;i<=n+1;i++){
			int x=ord[i];
			while(!q[x].empty()){
				int id=q[x].front();q[x].pop();
				res[id]=seq[cur++];
			}
		}
		for(int i=1;i<=n;i++) printf("%d%c",res[i]," \n"[i==n]);
	}
}
int main(){
	int qu;scanf("%d",&qu);
	while(qu--) solve();
	return 0;
}