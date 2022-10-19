#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool chmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool chmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=60;
int m,n,t_case;
char s[maxn][maxn];
#define pb push_back
#define pp pop_back
#define eb emplace_back
#define SZ(k) k.size()
#define ALL(k) k.begin(),k.end()
#define RALL(k) k.rend(),k.rbegin()
typedef pair<int,int> pii;
#define fi first
#define se second
#define mp make_pair
vector<pii>x,y;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&m);
		x.clear(),y.clear();
		for(ri i=1;i<=n;++i){
			scanf("%s",s[i]+1);
			for(ri j=1;j<=m;++j){
				if(s[i][j]=='R')x.pb({i,j});
				if(s[i][j]=='W')y.pb({i,j});
			}
		}
		bool flag=false;
		for(auto i:x)
			for(auto j:x)
				if((abs(i.fi-j.fi)+abs(i.se-j.se))&1)
					flag=true;
		for(auto i:y)
			for(auto j:y)
				if((abs(i.fi-j.fi)+abs(i.se-j.se))&1)
					flag=true;
		for(auto i:x)
			for(auto j:y)
				if((abs(i.fi-j.fi)+abs(i.se-j.se))%2==0)
					flag=true;
		if(flag){puts("NO");continue;}
		puts("YES");
		flag=false;
		for(auto i:x)
			if((abs(i.fi-1)+abs(i.se-1))%2==0)
				flag=true;
		for(auto i:y)
			if((abs(i.fi-1)+abs(i.se-1))&1)
				flag=true;
		if(!flag){
			for(ri i=1;i<=n;++i,puts(""))
				for(ri j=1;j<=m;++j)
					putchar(((abs(i-1)+abs(j-1))%2==0)?'W':'R');
		}
		else{
			for(ri i=1;i<=n;++i,puts(""))
				for(ri j=1;j<=m;++j)
					putchar(((abs(i-1)+abs(j-1))%2==0)?'R':'W');
		}
	}
	return 0;
}