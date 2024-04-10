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
const int MAXN=2e5;
const int ALPHA=26;
struct acam{
	int ch[MAXN+5][ALPHA+2],ncnt=0,fail[MAXN+5],cnt[MAXN+5];
	void insert(char *s){
		int len=strlen(s+1),cur=0;
		for(int i=1;i<=len;i++){
			if(!ch[cur][s[i]-'a']) ch[cur][s[i]-'a']=++ncnt;
			cur=ch[cur][s[i]-'a'];
		} cnt[cur]++;
	}
	void getfail(){
		queue<int> q;
		for(int i=0;i<ALPHA;i++) if(ch[0][i]) q.push(ch[0][i]);
		while(!q.empty()){
			int x=q.front();q.pop();
			for(int i=0;i<ALPHA;i++){
				if(ch[x][i]) fail[ch[x][i]]=ch[fail[x]][i],cnt[ch[x][i]]+=cnt[fail[ch[x][i]]],q.push(ch[x][i]);
				else ch[x][i]=ch[fail[x]][i];
			}
		}
	}
	int num[MAXN+5];
	void walk(char *s){
		int len=strlen(s+1),cur=0;
		for(int i=1;i<=len;i++){
			cur=ch[cur][s[i]-'a'];
			num[i]=cnt[cur];
		}
	}
} x,y;
int n;
char s[MAXN+5],buf[MAXN+5];
int main(){
	scanf("%s%d",s+1,&n);
	for(int i=1;i<=n;i++){
		scanf("%s",buf+1);x.insert(buf);
		int len=strlen(buf+1);reverse(buf+1,buf+len+1);y.insert(buf);
	} x.getfail();y.getfail();
	x.walk(s);int len=strlen(s+1);reverse(s+1,s+len+1);y.walk(s);
	ll ans=0;for(int i=1;i<len;i++) ans+=1ll*y.num[len-i]*x.num[i];
	printf("%lld\n",ans);
	return 0;
}