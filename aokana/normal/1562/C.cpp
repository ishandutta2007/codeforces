#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],m,n,t_case;
char s[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%s",&n,s+1);
		bool flag=false;
		for(ri i=1;i<=n;++i)
			if(s[i]=='0'){
				flag=true;
				if(i>n/2)printf("%d %d %d %d\n",1,i,1,i-1);
				else printf("%d %d %d %d\n",i,n,i+1,n);
				break;
			}
		if(!flag)printf("%d %d %d %d\n",1,n/2,n-(n/2)+1,n);
	}
	return 0;
}