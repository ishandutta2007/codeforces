#include<cstdlib>
#include<cstdio>
#include<algorithm>
#define N 400100
using namespace std;
struct stu{
	long long w,r;
	bool operator<(const stu& o)const{return (w*o.w<0)^(r*o.w<o.r*w);}
	bool operator!=(const stu& o)const{return w*o.r!=r*o.w;}
}s[N];
int main(){
	int p0=0,n0=0,pc=0,nc=0;
	long long pt=0,nt=0,ans=0;
	int n,c,d,m=0;
	scanf("%d%d%d",&n,&c,&d);
	for(int i=0;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		if(y==d){
			if(x>c) p0++;
			else n0++;
		}
		else{
			s[m].r=x-c;
			s[m].w=y-d;
			m++;
		}
	}
	sort(s,s+m);
	for(int i=0,j=0;i<m;i++){
		if(s[i].w>0){
			ans+=nt;
			ans+=1LL*n0*nc;
		}
		else{
			ans+=pt;
			ans+=1LL*p0*pc;
		}
		if(i+1<m&&s[i]!=s[i+1]){
			int tpc=0,tnc=0;
			while(j<i+1){
				if(s[j].w>0) tpc++;
				else tnc++;
				j++;
			}
			nt+=1LL*tnc*pc;
			pt+=1LL*tpc*nc;
			pc+=tpc;
			nc+=tnc;
		}
	}
	printf("%I64d\n",ans);
	return 0;
}