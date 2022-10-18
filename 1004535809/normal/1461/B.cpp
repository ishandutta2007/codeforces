#include <bits/stdc++.h>
using namespace std;
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define fi first
#define se second
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
template<typename T>
void read(T &x){
	char c=getchar();T neg=1;
	while(!isdigit(c)){
		if(c=='-') neg=-1;
		c=getchar();
	}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x*=neg;
}
const int MAXN=500;
int n,m;
char s[MAXN+5][MAXN+5];
int s1[MAXN+5][MAXN+5],s2[MAXN+5][MAXN+5];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);memset(s,0,sizeof(s));
		for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
		memset(s1,0,sizeof(s1));memset(s2,0,sizeof(s2));
		for(int i=n;i;i--) for(int j=1;j<=m;j++) s1[i][j]=(s1[i+1][j-1]+(s[i][j]=='*'));
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) s2[i][j]=(s2[i-1][j-1]+(s[i][j]=='*'));
		int ret=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				int mn=min(min(j,m-j+1),i);
				for(int k=0;k<mn;k++){
					if((s1[i-k][j]-s1[i+1][j-k-1])==(k+1)&&(s2[i][j+k]-s2[i-k-1][j-1])==(k+1)) ret++;
					else break;
				}
			}
		} printf("%d\n",ret);
	}
	return 0;
}