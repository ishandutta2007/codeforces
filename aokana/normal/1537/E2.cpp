#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool chmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool chmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=5e5+10;
int m,n,t_case;
vector<int>pri;
char s[maxn],t[maxn];
int main(){
	scanf("%d%d%s",&n,&m,t+1);
	ri k=min(m,n),pos=1;
	for(ri i=2;i<=k;++i)
		if(t[i]<t[(i-1)%pos+1])
			pos=i;
		else if(t[i]>t[(i-1)%pos+1])break;
	for(ri i=1,j=1;i<=pos&&j<=m;++j){
		putchar(t[i]);
		if(i==pos)i=1;
		else ++i;
	}
	return 0;
}