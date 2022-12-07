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
int n,a[100005],b[100005],c[100005],d[100005];
int main() {
	read(n);
	for(int i=1;i<=n;++i)
		read(a[i]),b[i]=a[i]-a[i-1];
	for(int i=1;i<=n;++i)
		read(c[i]),d[i]=c[i]-c[i-1];
	if(a[1]!=c[1]||a[n]!=c[n])
		return 0*puts("No");
	sort(b+1,b+n+1),sort(d+1,d+n+1);
	for(int i=1;i<=n;++i)
		if(b[i]!=d[i])
			return 0*puts("No");
	puts("Yes");
}