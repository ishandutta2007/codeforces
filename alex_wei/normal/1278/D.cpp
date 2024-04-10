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

const int N=5e5+5;

struct seg{
	int l,r;
	bool operator < (const seg &v) const {
		return l<v.l;
	}
}c[N];
set <pii> s;
set <pii> :: iterator it;
int n,deg,f[N];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}

int main(){
	n=read();
	for(int i=1;i<=n;i++)c[i].l=read(),c[i].r=read(),f[i]=i;
	sort(c+1,c+n+1);
	for(int i=1;i<=n;i++){
		while(s.size()&&(*s.begin()).fi<c[i].l)s.erase(s.begin());
		pii d={c[i].r,i};
		if(s.size()){
			it=s.lower_bound(d);
			while(it!=s.begin()){
				int ind=find((*--it).se);
				if(ind==i)puts("NO"),exit(0);
				else f[ind]=i,deg++;
			}
		}
		s.insert(d);
		if(deg>=i)puts("NO"),exit(0);
	}
	puts(deg==n-1?"YES":"NO");
	
	return 0; 
}