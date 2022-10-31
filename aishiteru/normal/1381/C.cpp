#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
#define it register int
#define ct const int
#define il inline
using namespace std;
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
};
using io :: fr;
struct ky{
	int x,id;
	bool operator < (const ky&p)const{
		return x^p.x?x<p.x:id<p.id;
	}
};
const int N=1000005;
vector<int> g[N],vec;
priority_queue<ky> q;
int T,n,non,x,y,cn,a[N],ans[N];
int main(){ 
	scanf("%d",&T);it i,non,j;
	while(T--){
		scanf("%d%d%d",&n,&x,&y),non=-1;
		if(y<x){puts("NO");continue;}
		for(i=n+1;i;--i) g[i].clear();vec.clear();
		for(i=1;i<=n;++i) scanf("%d",&a[i]),g[a[i]].push_back(i);
		while(!q.empty()) q.pop();
		for(i=n+1;i;--i) g[i].size()?q.push((ky){g[i].size(),i}),0:non=i;
		for(i=1;i<=x;++i){
			j=q.top().id,q.pop(),ans[g[j].back()]=j,g[j].pop_back();
			if(g[j].size()) q.push((ky){g[j].size(),j});
		}
		while(!q.empty()){
			i=q.top().id,q.pop();
			for(const int &j: g[i]) vec.push_back(j);
		}
		y-=x,cn=0;
		for(it i=0,sz=vec.size();i<sz;++i)
			cn<y&&a[vec[i]]!=a[vec[(i+(sz>>1))%sz]]?ans[vec[i]]=a[vec[(i+(sz>>1))%sz]],++cn:ans[vec[i]]=non;
		if(cn<y){puts("NO");continue;}
		puts("YES");for(i=1;i<=n;++i) printf("%d ",ans[i]);puts("");
	}
	return 0;
}