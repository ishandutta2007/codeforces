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
int n,q;
ll s[100005],dif[100005],sum[100005],ans[100005],l,r;
struct Node {
	ll len;
	int id;
	inline bool operator < (const Node &rhs) const {
		return len<rhs.len;
	}
}t[100005];
int main() {
	read(n);
	for(int i=1;i<=n;++i)
		read(s[i]);
	sort(s+1,s+n+1),read(q);
	for(int i=1;i<n;++i)
		dif[i]=s[i+1]-s[i];
	for(int i=1;i<=q;++i)
		read(l),read(r),t[i]=(Node){r-l+1,i};
	sort(dif+1,dif+n),sort(t+1,t+q+1);
	for(int i=1;i<n;++i)
		sum[i]=sum[i-1]+dif[i];
	for(int i=1;i<=q;++i) {
		int p=lower_bound(dif+1,dif+n,t[i].len)-dif-1;
//		cerr<<p<<" "<<dif[p]<<" "<<sum[p]<<endl;
		ans[t[i].id]=1ll*n*t[i].len-1ll*t[i].len*p+sum[p];
	}
	for(int i=1;i<=q;++i)
		printf("%lld ",ans[i]);
	puts("");
}