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

const int N=1e5+5;

int n,sa[N],ea[N],sb[N],eb[N];

struct op{
	int s,e,t,o;
	bool operator < (const op &v) const {
		return t==v.t?o<v.o:t<v.t;
	}
}p[N<<1];

bool solve(){
	multiset <int> s,e;
	for(int i=0;i<n;i++){
		p[i<<1]={sb[i],eb[i],sa[i],1};
		p[i<<1|1]={sb[i],eb[i],ea[i]+1,0};
	}
	sort(p,p+(n<<1));
	for(int i=0;i<n<<1;i++){
		if(p[i].o){
			if(s.size()&&(p[i].e<*s.rbegin()||*e.begin()<p[i].s))return true;
			s.insert(p[i].s),e.insert(p[i].e);
		}
		else s.erase(s.find(p[i].s)),e.erase(e.find(p[i].e));
	}
	return false;
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>sa[i]>>ea[i]>>sb[i]>>eb[i];
	if(solve())puts("NO"),exit(0);
	swap(sa,sb),swap(ea,eb);
	if(solve())puts("NO");
	else puts("YES");
	
	return 0; 
}