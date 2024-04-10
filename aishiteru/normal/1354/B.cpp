#include<bits/stdc++.h>
#define it register int
#define ct const int
#define il inline
using namespace std;
typedef long long ll;
#define rll register ll
#define cll const ll
typedef double db;
#define rdb register db
#define cdb const db
namespace io{
	il char nc(){
		static char buf[100000],*p1=buf,*p2=buf;
		return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++; 
	}
	template <class I> 
	il void fr(I &num){
		num=0;register char c=nc();it p=1;
		while(c<'0'||c>'9') c=='-'?p=-1,c=nc():c=nc();
		while(c>='0'&&c<='9') num=num*10+c-'0',c=nc();
		num*=p;
	} 
	template <class I> 
	il I Max(I p,I q){return p>q?p:q;}
	template <class I> 
	il I Min(I p,I q){return p<q?p:q;}
	template <class I> 
	il I A(I x){return x<0?-x:x;}
	template <class I> 
	il void sp(I&p,I&q){I x=p;p=q,q=x;}
	template <class I> 
	il void ckMax(I& p,I q){p=(p>q?p:q);}
	template <class I> 
	il void ckMin(I& p,I q){p=(p<q?p:q);}
};
using io :: fr;
using io :: nc;
using io :: Max;
using io :: Min;
using io :: A;
using io :: sp;
using io :: ckMax;
using io :: ckMin;
const int N=1000005;
int T,n;
char s[N];
vector<int> pos[3];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1),n=strlen(s+1);it ans=n+1,i;
		pos[1].clear(),pos[2].clear(),pos[3].clear();
		for(i=1;i<=n;++i) pos[s[i]-'0'].push_back(i);
		for(i=1;i<=n;++i){
			it mx=i;
			for(it j=1;j<=3;++j){
				auto p=std::lower_bound(pos[j].begin(),pos[j].end(),i);
				if(p==pos[j].end()){mx=-1;break;}
		//		printf("%d ",pos[j][p-pos[j].begin()]);
				ckMax(mx,pos[j][p-pos[j].begin()]);
			}
		//	printf("mx=%d i=%d\n",mx,i);
			if(mx>i) ckMin(ans,mx-i+1);
		}
		printf("%d\n",ans==n+1?0:ans);
	}
	return 0;
}