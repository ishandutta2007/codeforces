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
string s;
int l,r,u,d,ll,rr,uu,dd;
map <int,int> a,b;

void move(int &x,int &y,char dir){
	if(dir=='W')x++;
	if(dir=='S')x--;
	if(dir=='A')y--;
	if(dir=='D')y++;
}

void solve(){
	cin>>s;
	ll=rr=uu=dd=0,a.clear(),b.clear();
	int nx=0,ny=0; a[0]=b[0]=100000;
	for(int i=0;i<s.size();i++){
		move(nx,ny,s[i]);
		a[nx]++,b[ny]++;
		ll=min(ll,ny),rr=max(rr,ny);
		uu=max(uu,nx),dd=min(dd,nx);
	}
	bool row=0,col=0;
	l=r=ny,u=d=nx;
	for(int i=s.size()-1;~i;i--){
		a[nx]--,b[ny]--;
		if(s[i]=='W'){
			row|=nx==uu&&!a[nx]&&d!=dd;
			move(nx,ny,'S');
		}
		if(s[i]=='S'){
			row|=nx==dd&&!a[nx]&&u!=uu;
			move(nx,ny,'W');
		}
		if(s[i]=='A'){
			col|=ny==ll&&!b[ny]&&r!=rr;
			move(nx,ny,'D');
		}
		if(s[i]=='D'){
			col|=ny==rr&&!b[ny]&&l!=ll;
			move(nx,ny,'A');
		}
		l=min(l,ny),r=max(r,ny);
		u=max(u,nx),d=min(d,nx);
	}
	long long ans=1ll*(rr-ll+1)*(uu-dd+1);
	if(row)ans=min(ans,1ll*max(2,uu-dd)*(rr-ll+1));
	if(col)ans=min(ans,1ll*(uu-dd+1)*max(2,rr-ll));
	printf("%lld\n",ans);
}

int main(){
	
	int testcase;
	cin>>testcase;
	while(testcase--)solve();
	
	return 0;
}
/*
1
WSSWW
*/