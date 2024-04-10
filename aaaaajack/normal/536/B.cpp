#include<cstdio>
#define N 1000100
#define Q 1000000007
using namespace std;
char s[N];
int f[N];
bool e[N];
int qp(int p){
	int x=26,r=1;
	while(p){
		if(p&1) r=1LL*r*x%Q;
		x=1LL*x*x%Q;
		p>>=1;
	}
	return r;
}
int main(){
	int i,n,m,tmp,l,x,pe=0,ans=0;
	bool wrong=false;
	scanf("%d%d",&n,&m);
	scanf("%s",s);
	for(i=0;s[i];i++){
		tmp=f[i];
		while(tmp&&s[tmp]!=s[i]) tmp=f[tmp];
		if(i){
			if(s[tmp]==s[i]){
				f[i+1]=tmp+1;
			}
			else{
				f[i+1]=0;
			}
		}
	}
	l=i;
	for(tmp=l;tmp;tmp=f[tmp]){
		e[tmp]=true;
	}
	for(i=0;i<m;i++){
		scanf("%d",&x);
		if(x>pe){
			ans+=x-pe-1;
		}
		else if(!e[pe-x+1]){
			wrong=true;
		}
		pe=x+l-1;
	}
	ans+=n-pe;
	if(wrong) printf("%d\n",0);
	else printf("%d\n",qp(ans));
	return 0;
}