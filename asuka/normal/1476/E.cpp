#include<bits/stdc++.h>
#define ll long long
#define N 100015
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
#define SZ(x) ((int)x.size())
using namespace std;
int n,m,k;
map<string,int> M;
string s[N],t[N];
int mt[N],deg[N];
VI e[N],ans;
queue<int> q; 
bool ok(char ss,char tt){
	return (ss==tt||ss=='_');
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d%d%d",&n,&m,&k);
 	rep(i,1,n) cin>>s[i],M[s[i]] = i;
 	rep(i,1,m) cin>>t[i]>>mt[i];
 	rep(i,1,m){
 		rep(j,0,k-1) if(!ok(s[mt[i]][j],t[i][j])){
 			cerr << i << endl;
 			puts("NO");
 			return 0;
 		}
 	}
 	rep(i,1,m){
 		int all = (1<<k)-1;
 		rep(s,0,all){
 			string cur = t[i];
 			rep(j,0,k-1){
 				if((1<<j)&s) cur[j] = '_';
 			}
 			// cerr << t[i] << ' ' << cur << endl;
 			if(M.count(cur) > 0){
 				// cerr << t[i] << ' ' << cur << endl;
 				int pos = M[cur];
 				if(pos == mt[i]) continue;
 				e[pos].pb(mt[i]); deg[mt[i]]++;
 				// cerr << pos << " -> " << mt[i] << endl;
 			}
 		}
 	}
 	rep(i,1,n) if(deg[i] == 0) q.push(i);
 	while(!q.empty()){
 		int u = q.front(); q.pop(); ans.pb(u);
 		for(auto v:e[u]){
 			if(--deg[v] == 0) q.push(v);
 		}
 	}
 	if(SZ(ans) != n){
 		puts("NO"); return 0;
 	}
 	reverse(all(ans));
 	puts("YES");
 	for(auto v:ans) printf("%d ",v);
	return 0;
}