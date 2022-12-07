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
const int mod=998244353;
int n,a[100005],f[100005][205][2];
inline int Add(int x,int y) {
	return (x+=y)>=mod?x-mod:x;
}
inline int Sub(int x,int y) {
	return (x-=y)<0?x+mod:x;
}
int main() {
	read(n);
	for(int i=1;i<=n;++i)
		read(a[i]);
	if(~a[1])
		f[1][a[1]][0]=1;
	else
		for(int i=1;i<=200;++i)
			f[1][i][0]=1;
	for(int i=2;i<=n;++i) {
		if(~a[i]) {
			for(int j=1;j<=200;++j) {
				if(f[i-1][j][0]&&a[i]>j)
					f[i][a[i]][0]=Add(f[i][a[i]][0],f[i-1][j][0]);
				if(f[i-1][j][0]&&a[i]==j)
					f[i][a[i]][1]=Add(f[i][a[i]][1],f[i-1][j][0]);
				if(f[i-1][j][1]) {
					if(a[i]<=j)
						f[i][a[i]][1]=Add(f[i][a[i]][1],f[i-1][j][1]);
					else
						f[i][a[i]][0]=Add(f[i][a[i]][0],f[i-1][j][1]);
				}
			}
		}
		else {
			for(int j=1;j<=200;++j) {
				if(f[i-1][j][0])
					f[i][j+1][0]=Add(f[i][j+1][0],f[i-1][j][0]),
					f[i][j][1]=Add(f[i][j][1],f[i-1][j][0]),
					f[i][j+1][1]=Sub(f[i][j+1][1],f[i-1][j][0]);
				if(f[i-1][j][1])
					f[i][1][1]=Add(f[i][1][1],f[i-1][j][1]),
					f[i][j+1][1]=Sub(f[i][j+1][1],f[i-1][j][1]),
					f[i][j+1][0]=Add(f[i][j+1][0],f[i-1][j][1]);
			}
			for(int j=1;j<=200;++j)
				f[i][j][0]=Add(f[i][j][0],f[i][j-1][0]),
				f[i][j][1]=Add(f[i][j][1],f[i][j-1][1]);
		}
	}
	int ans=0;
	for(int i=1;i<=200;++i)
		ans=Add(ans,f[n][i][1]);
	printf("%d\n",ans);
}