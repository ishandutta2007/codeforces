#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],cnt[26],m,n,t_case;
char s[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%s",s+1);
		n=strlen(s+1);
		memset(cnt,0,sizeof cnt);
		for(ri i=1;i<=n;++i)++cnt[s[i]-'a'];
		for(ri i=1;i<=n;++i){
			if(cnt[s[i]-'a']==1){
				puts(s+i);
				break;
			}
			--cnt[s[i]-'a'];
		}
		memset(s,0,n+1);
	}
	return 0;
}