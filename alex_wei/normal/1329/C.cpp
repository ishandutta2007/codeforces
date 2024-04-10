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

const int N=1<<21;

int testcase;

int n,h,g,pd,a[N],b[N],stc[N],top;

void f(int x){
	stc[++top]=x,a[stc[top]]=0;
	if(a[x<<1]>0||a[x<<1|1]>0){
		if(a[x<<1]>a[x<<1|1])a[x]=a[x<<1],f(x<<1);
		else a[x]=a[x<<1|1],f(x<<1|1);
	}
	if(a[x]==0&&x<1<<g)pd=1;
}

vector <int> op;

void d(int x){
	if(x<1<<h){
		while(a[x]&&!pd){
			f(x);
			if(pd)while(top)a[stc[top]]=b[stc[top]],top--;
			else{
				while(top)b[stc[top]]=a[stc[top]],top--;
				op.pb(x);
			}
		}
		pd=0,d(x<<1),d(x<<1|1);
	}
}

void solve(){
	h=read(),g=read();
	for(int i=1;i<1<<h;i++)b[i]=a[i]=read();
	d(1);
	ll ans=0;
	for(int i=1;i<1<<g;i++)ans+=a[i];
	cout<<ans<<endl;
	for(auto it:op)cout<<it<<" ";
	op.clear();
	for(int i=1;i<1<<h;i++)b[i]=a[i]=0;
}

int main(){
	cin>>testcase;
//	t=1;
	while(testcase--)solve();
}