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
int n,h,a[1005],b[1005];
int main() {
	read(n),read(h);
	for(int i=1;i<=n;++i)
		read(a[i]);
	for(int x=n;x;--x) {
		memcpy(b,a,sizeof a),sort(b+1,b+x+1),reverse(b+1,b+x+1);
		ll c=0,d=0;
		for(int i=1;i<=x;++i)
			if(i&1)
				c+=b[i];
			else
				d+=b[i];
		if(c<=h&&d<=h)
			return 0*printf("%d\n",x);
	}
	puts("0");
}