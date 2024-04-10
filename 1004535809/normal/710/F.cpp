#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
template<typename T> void read(T &x){
	char c=getchar();T neg=1;
	while(!isdigit(c)){if(c=='-') neg=-1;c=getchar();}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x*=neg;
}
const int MAXN=3e5;
const int LOG_N=19;
const int ALPHA=26;
class solver{
public:
	int sz[LOG_N+3],rt[LOG_N+3],cnt=0;
	int oc[MAXN*2+5][ALPHA+2],ch[MAXN*2+5][ALPHA+2],ncnt=0,ed[MAXN*2+5],val[MAXN*2+5],fail[MAXN+5];
	void insert(char *s,int r){
		int len=strlen(s+1),cur=r;
		for(int i=1;i<=len;i++){
			if(!oc[cur][s[i]-'a']) oc[cur][s[i]-'a']=++ncnt;
			cur=oc[cur][s[i]-'a'];
		} ed[cur]++;
	}
	void getfail(int r){
		queue<int> q;
		for(int i=0;i<ALPHA;i++){
			if(oc[r][i]){
				fail[oc[r][i]]=r;q.push(oc[r][i]);
				val[oc[r][i]]=ed[oc[r][i]];ch[r][i]=oc[r][i];
			} else ch[r][i]=r;
		}
		while(!q.empty()){
			int x=q.front();q.pop();
			for(int i=0;i<ALPHA;i++){
				if(oc[x][i]){
					ch[x][i]=oc[x][i];
					fail[oc[x][i]]=ch[fail[x]][i];
					val[oc[x][i]]=val[fail[oc[x][i]]]+ed[oc[x][i]];
					q.push(oc[x][i]);
				} else ch[x][i]=ch[fail[x]][i];
			}
		}
	}
	int merge(int x,int y){
		if(!x||!y) return x+y;
		ed[x]+=ed[y];
		for(int i=0;i<ALPHA;i++) oc[x][i]=merge(oc[x][i],oc[y][i]);
		return x;
	}
	void insert(char *s){
		sz[++cnt]=1;rt[cnt]=++ncnt;insert(s,rt[cnt]);
		while(sz[cnt]==sz[cnt-1]){
			rt[cnt-1]=merge(rt[cnt-1],rt[cnt]);
			sz[cnt-1]<<=1;sz[cnt]=0;cnt--;
		} getfail(rt[cnt]);
	}
	int query(char *s,int r){
		int len=strlen(s+1),cur=r,ret=0;
		for(int i=1;i<=len;i++){
			cur=ch[cur][s[i]-'a'];
			ret+=val[cur];
		} return ret;
	}
	int query(char *s){
		int ret=0;
		for(int i=1;i<=cnt;i++) ret+=query(s,rt[i]);
		return ret;
	}
} s1,s2;
char buf[MAXN+5];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		int opt;scanf("%d%s",&opt,buf+1);
		if(opt==1) s1.insert(buf);
		else if(opt==2) s2.insert(buf);
		else printf("%d\n",s1.query(buf)-s2.query(buf)),fflush(stdout);
	}
	return 0;
}