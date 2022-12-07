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
int n,m,a[505][505],b[505][505];
int main() {
	read(n),read(m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			read(a[i][j]);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			read(b[i][j]);
	for(int i=1;i<n;++i)
		for(int j=1;j<m;++j)
			if(a[i][j]!=b[i][j])
				a[i][j]^=1,a[i+1][j]^=1,a[i][j+1]^=1,a[i+1][j+1]^=1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(a[i][j]!=b[i][j])
				return 0*puts("No");
	puts("Yes");
}