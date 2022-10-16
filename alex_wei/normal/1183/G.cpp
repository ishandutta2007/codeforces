/*
	Templates start.
	Powered by c++11.
	Author : Alex_Wei.
*/

//#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

// IO templates.

char buf[1<<21],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
#ifdef __WIN64
	#define gc getchar()
#else
	#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
#endif
#define pc(x) (*O++=x)
#define flush() fwrite(obuf,O-obuf,1,stdout)

inline int read(){
	int x=0,sign=0; char s=getchar();
	while(!isdigit(s))sign|=s=='-',s=getchar();
	while(isdigit(s))x=(x<<1)+(x<<3)+(s-'0'),s=getchar();
	return sign?-x:x;
}
void print(int x) {if(x>9)print(x/10); pc(x%10+'0');}

#define ll long long
#define pii pair <int,int>
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
#define sor(x) sort(all(x))
#define rev(x) reverse(all(x))
#define mem(x,v) memset(x,v,sizeof(x))

/*
	Templates end.
	Please give me more points.
*/

const int N=2e5+5;

int n;
pii buc[N];
vector <int> g[N];
priority_queue <int> q;

void solve(){
	cin>>n;
	while(q.size())q.pop();
	for(int i=1;i<=n;i++)buc[i].fi=buc[i].se=0,g[i].clear();
	for(int i=1;i<=n;i++){
		int a,n;
		cin>>a>>n;
		buc[a].fi++,buc[a].se+=n;
	}
	int ans=0,ans2=0;
	for(int i=1;i<=n;i++)g[buc[i].fi].pb(buc[i].se);
	for(int i=n;i;i--){
		for(int it:g[i])q.push(it);
		if(q.size())ans+=i,ans2+=min(q.top(),i),q.pop();
	}
	printf("%d %d\n",ans,ans2);
}

int main(){
	int testcase;
	cin>>testcase;
	while(testcase--)solve();
	
	return 0;
}