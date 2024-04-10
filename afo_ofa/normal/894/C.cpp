#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}
template<class T>inline void print(T x){if(x/10!=0)print(x/10);putchar(x%10+'0');}
template<class T>inline void writeln(T x){if(x<0)putchar('-');x=abs(x);print(x);putchar('\n');}
template<class T>inline void write(T x){if(x<0)putchar('-');x=abs(x);print(x);}
/*================Header Template==============*/
int seq[1005],n;
bool vis[1000010],x;
inline bool cmp(int a,int b){return a>b;}
inline int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main() {
	read(n);
	for(int i=1;i<=n;i++) {
		read(seq[i]);
		vis[seq[i]]=1;
	}
	int g=seq[1];
	for(int i=2;i<=n;i++) {
		g=gcd(g,seq[i]);
		if(!vis[g]) {
			puts("-1");
			return 0;
		}
	}
	writeln(n*2);
	for(int i=1;i<=n;i++)
		printf("%d %d ",seq[i],g);
	return 0;
}