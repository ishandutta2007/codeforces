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
int n,x,cnt[4][10],now[10],vis[4],pos;
inline bool dfs(int p) {
	if(p==pos+1)
		return 1;
	bool ans=0;
	for(int i=1;i<=n;i++) {
		if(!vis[i]&&cnt[i][now[p]]) {
			vis[i]=1;
			ans|=dfs(p+1);
			vis[i]=0;
		}
	}
	return ans;
}
int main() {
	read(n);
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=6;j++) {
			read(x);
			cnt[i][x]++;
		}
	}
	for(int i=1;i<=1000;i++) {
		if(i==1000) {
			writeln(999);
			return 0;
		}
		int tmp=i;
		pos=0;
		while(tmp) {
			now[++pos]=tmp%10;
			tmp/=10;
		}
		if(!dfs(1)) {
			writeln(i-1);
			return 0;
		}
	}
}