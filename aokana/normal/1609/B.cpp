#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],ans[maxn],cnt,m,n,t_case;
char s[maxn],t[5];
inline int calc(int pos){
	if(pos<1||pos+2>n)return 0;
	return s[pos]=='a'&&s[pos+1]=='b'&&s[pos+2]=='c';
}
int main(){
		scanf("%d%d%s",&n,&m,s+1);
		cnt=0;
		for(ri i=1;i<=n;++i){
			ans[i]=calc(i);
			cnt+=ans[i];
		}
		while(m--){
			ri pos;
			scanf("%d%s",&pos,t);
			s[pos]=*t;
			for(ri i=pos-2;i<=pos;++i)
				if(i>0){
					cnt-=ans[i];
					ans[i]=calc(i);
					cnt+=ans[i];
				}
			printf("%d\n",cnt);
		}
	return 0;
}