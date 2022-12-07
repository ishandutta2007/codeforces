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
#define int long long
const int maxn=1000006;
int n,m,cnt[maxn],f[maxn][5][3],ans;
signed main() {
	read(n),read(m);
	for(int i=1,x;i<=n;++i)
		read(x),++cnt[x];
	f[1][0][0]=0;
	for(int i=1;i<=m;++i)
		for(int j=0;j<5;++j)
				for(int k=0;k<3;++k) {
					ans=max(ans,f[i+1][k][0]=max(f[i+1][k][0],f[i][j][k]+(cnt[i]-j)/3));
					if(cnt[i]>j&&cnt[i+1]>k&&cnt[i+2])
						ans=max(ans,f[i+1][k+1][1]=max(f[i+1][k+1][1],f[i][j][k]+1+(cnt[i]-j-1)/3));
					if(cnt[i]>j+1&&cnt[i+1]>k+1&&cnt[i+2]>1)
						ans=max(ans,f[i+1][k+2][2]=max(f[i+1][k+2][2],f[i][j][k]+2+(cnt[i]-j-2)/3));
				}
	printf("%lld\n",ans);
}