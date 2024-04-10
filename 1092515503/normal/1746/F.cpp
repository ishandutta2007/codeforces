/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETERMINEDLY!
*/
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
map<int,ull>mp;
int n,m,a[300100];
struct checker{
int t[300100];
void ADD(int x,int y){while(x<=n)t[x]+=y,x+=x&-x;}
int SUM(int x){int ret=0;while(x)ret+=t[x],x-=x&-x;return ret;}
int RANGE(int l,int r){return SUM(r)-SUM(l-1);}
}c[64];
mt19937_64 rnd(time(0));
namespace FIFO{
char buf[1<<23],*p1=buf,*p2=buf;
#ifndef Troverld
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
#else
#define gc() getchar()
#endif
template<typename T>void read(T&x){
	x=0;
	char c=gc();
	while(c>'9'||c<'0')c=gc();
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=gc();
}
template<typename T>void print(T x){if(x<=9)putchar('0'+x);else print(x/10),putchar('0'+x%10);}
}using namespace FIFO;
int main(){
	read(n),read(m);
	for(int i=1;i<=n;i++){
		read(a[i]);
		if(mp.find(a[i])==mp.end())mp[a[i]]=rnd();
		ull x=mp[a[i]];
		for(int j=0;j<60;j++)if((x>>j)&1)c[j].ADD(i,1);
	}
	for(int i=1,tp,x,y,z;i<=m;i++){
		read(tp);
		if(tp==1){
			read(x),read(y);
			ull u=mp[a[x]];
			if(mp.find(y)==mp.end())mp[y]=rnd();
			ull v=mp[y];
			for(int j=0;j<60;j++){
				int val=((v>>j)&1)-((u>>j)&1);
				if(val)c[j].ADD(x,val);
			}
			a[x]=y;
		}else{
			read(x),read(y),read(z);
			if((y-x+1)%z){puts("NO");continue;}
			bool ok=true;
			for(int j=0;j<60;j++)if(c[j].RANGE(x,y)%z){ok=false;break;}
			puts(ok?"YES":"NO");
		}
	}
	return 0;
}