/*
	Templates start.
	Powered by c++11.
	Author : Alex_Wei.
*/

#pragma GCC optimize(3)

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

const int N=3e5+5;

int a[N],b[N],n,neg,pos;
void solve(){
	cin>>n;
	neg=pos=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=1;i<=n;i++){
		if(!neg&&!pos){
			if(a[i]!=b[i]){
				puts("NO");
				return;
			}
		}
		else if(!neg){
			if(a[i]>b[i]){
				puts("NO");
				return;
			}
		}
		else if(!pos){
			if(a[i]<b[i]){
				puts("NO");
				return;
			}
		}
		if(a[i]==-1)neg=1;
		if(a[i]==1)pos=1;
	}
	puts("YES");
}

int main(){
	int testcase=1;
	cin>>testcase;
	while(testcase--)solve();
	
	return 0;
}