#include<bits/stdc++.h>
#define ll long long
#define N
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
using namespace std;
int n,m,odd,even;
map<pii,char> M;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d",&n,&m);
	while(m--){
		char s[3];
		int a,b;
		scanf("%s",s+1);
		if(s[1] == '+'){
			scanf("%d%d",&a,&b);
			scanf("%s",s+1);
			M[mp(a,b)] = s[1];
			if(M.count(mp(b,a))){
				odd++;
				if(M[mp(b,a)] == s[1]) even++;
			}
		}else if(s[1] == '-'){
			scanf("%d%d",&a,&b);
			if(M.count(mp(b,a))){
				odd--;
				if(M[mp(a,b)] == M[mp(b,a)]) even--;
			}
			M.erase(M.find(mp(a,b)));
		}else {
			scanf("%d",&a);
			if(a&1) puts(odd?"YES":"NO");
			else puts(even?"YES":"NO");
		}
	}
	return 0;
}