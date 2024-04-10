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
int n,m;
ll a[300005],b[300005],sa,sb;
inline int solve() {
	int p=1,q=1,res=0;
	while(p<=n&&q<=m) {
		if(a[p]==b[q])
			res++,p++,q++;
		else if(a[p]<b[q])
			a[p+1]+=a[p],p++;
		else
			b[q+1]+=b[q],q++;
	}
	return res;
}
inline void input() {
	read(n);
	for(int i=1;i<=n;++i)
		read(a[i]),sa+=a[i];
	read(m);
	for(int i=1;i<=m;++i)
		read(b[i]),sb+=b[i];
}
int main() {
	input();
	if(sa!=sb)
		return 0*puts("-1");
	printf("%d\n",solve());
}