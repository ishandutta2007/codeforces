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
int q,n;
int main() {
	for(read(q);q--;) {
		read(n);
		int cnt=0,tmp=n;
		while(tmp)
			++cnt,tmp>>=1;
		if(1<<cnt!=n+1) {
			printf("%d\n",(1<<cnt)-1);
			continue;
		}
		int ans=0;
		for(int i=1;i*i<=n;++i)
			if(n%i==0) {
				ans=max(ans,i);
				if(i!=1)
					ans=max(ans,n/i);
			}
		printf("%d\n",ans);
	}
}