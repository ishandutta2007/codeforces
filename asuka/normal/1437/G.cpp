#include<bits/stdc++.h>
#define ll long long
#define N 300015
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
#define all(x) x.begin(),x.end()
using namespace std;
int n,m,V[N];
char s[N];
namespace AC{
	int tr[N][26],fail[N],las[N],sz,ed[N],cnt[N];
	queue<int> q;
	multiset<int> S[N];
	void insert(char *s,int id){
		int u = 0;
		for(int i = 0;s[i];++i){
			if(!tr[u][s[i]-'a']) tr[u][s[i]-'a'] = ++sz;
			u = tr[u][s[i]-'a'];
		}
		ed[id] = u; cnt[u]++;
		S[u].insert(0);
	}
	void build(){
		rep(i,0,25) if(tr[0][i]) q.push(tr[0][i]);
		while(!q.empty()){
			int u = q.front(); q.pop();
			las[u] = cnt[fail[u]]>0?fail[u]:las[fail[u]];
			rep(i,0,25){
				if(tr[u][i]) fail[tr[u][i]] = tr[fail[u]][i] , q.push(tr[u][i]);
				else tr[u][i] = tr[fail[u]][i];
			}
		}
	}
	int query(char *s){
		int res = -1,u = 0;
		for(int i = 0;s[i];++i){
			//cout << s[i] << ' ';
			u = tr[u][s[i]-'a'];
			for(int j = u;j;j = las[j]) res = max(res,*S[j].rbegin());
		}
		return res;
	}
}
using namespace AC;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d%d",&n,&m);
 	//memset(V,-1,sizeof V);
 	rep(i,1,n){
 		scanf("%s",s);
 		insert(s,i);
 	}
 	rep(i,0,sz) S[i].insert(-1);
 	build();
 	rep(_,1,m){
 		int op; scanf("%d",&op);
 		if(op == 1){
 			int u,val; scanf("%d%d",&u,&val);
 			S[ed[u]].erase(S[ed[u]].find(V[u]));
 			V[u] = val;
 			S[ed[u]].insert(val);
 		}else{
 			scanf("%s",s);
 			printf("%d\n",query(s));
 		}
 	}
	return 0;
}