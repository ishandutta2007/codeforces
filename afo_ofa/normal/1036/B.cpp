#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}
template<class T>inline void print(T x){if(x/10!=0)print(x/10);putchar(x%10+'0');}
template<class T>inline void writeln(T x){if(x<0)putchar('-');x=abs(x);print(x);putchar('\n');}
template<class T>inline void write(T x){if(x<0)putchar('-');x=abs(x);print(x);}
/*================Header Template==============*/
int q;
ll n,m,k;
int main() {
	read(q);
	while(q--) {
		read(n),read(m),read(k);
		if(n<m)
			swap(n,m);
		if(n>k) {
			puts("-1");
			continue;
		}
		int p=(n+k)&1,q=(m+k)&1;
		if(p&&q) {
			printf("%lld\n",k-2);
			continue;
		}
		if(!p&&!q) {
			printf("%lld\n",k);
			continue;
		}
		printf("%lld\n",k-1);
//		printf("%lld\n",k-tmp+(tmp&1?tmp-1:tmp));
	}
}