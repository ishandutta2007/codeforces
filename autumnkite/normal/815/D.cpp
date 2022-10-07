#include <cstdio>
#include <cctype>
#include <algorithm>
#include <vector>
using namespace std;
int read(){
	int x=0;
	int f=1,ch=getchar();
	for (;!isdigit(ch)&&ch!=EOF;ch=getchar()) if (ch=='-') f=-1;
	for (;isdigit(ch);ch=getchar()) x=(x<<3)+(x<<1)+(ch^'0');
	return x*f;
}
const int N=500005;
int n,La,Lb,Lc,smx[N];
struct card{
	int b,c;
};
vector<card> d[N];
long long ans,sum[N];
int main(){
	n=read(),La=read(),Lb=read(),Lc=read(); //La,Lb,Lcp,q,r
	for (register int i=1;i<=n;++i){
		int a=min(La,read()),b=min(Lb,read()),c=min(Lc,read());
		d[a].push_back((card){b,c});
		smx[b]=max(smx[b],c);
	}
	for (register int i=Lb-1;i;--i) smx[i]=max(smx[i],smx[i+1]);
	for (register int i=1;i<=Lb;++i) sum[i]=sum[i-1]+smx[i]; //smx[i]
	int mxb=0,mxc=0,k=Lb+1; //
	for (register int x=La;x;--x){ //
		for (register int i=0;i<d[x].size();++i){
			int y=d[x][i].b,z=d[x][i].c;
			mxb=max(mxb,y),mxc=max(mxc,z); //mx2mx3
			while (k>mxb+1&&smx[k-1]<mxc) --k; //k
		}
		k=max(k,mxb+1); //
		ans+=1ll*(Lc-mxc)*(Lb-k+1)+1ll*Lc*(k-mxb-1)-sum[k-1]+sum[mxb]; //O(1)
	}
	printf("%lld",ans);
}