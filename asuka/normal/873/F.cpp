#include<bits/stdc++.h>
#define ll long long
#define N 200015
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
int n;
char s[N],v[N];
namespace SAM{
	int link[N<<1],len[N<<1],tr[N<<1][26],tot,las,siz[N<<1];
	void init(){link[0] = -1;}
	void ins(int c,int val){
		int cur = ++tot; siz[cur] = val;
		len[cur] = len[las]+1;
		int p = las;
		while(~p && !tr[p][c]) tr[p][c] = cur,p = link[p];
		if(p == -1) link[cur] = 0;
		else{
			int q = tr[p][c];
			if(len[p] + 1 == len[q]) link[cur] = q;
			else{
				int clone = ++tot;
				len[clone] = len[p]+1; link[clone] = link[q];
				rep(i,0,25) tr[clone][i] = tr[q][i];
				link[q] = link[cur] = clone;
				while(~p && tr[p][c] == q) tr[p][c] = clone,p = link[p];
			}
		}
		las = cur;
	}
}
using namespace SAM;
VI num;
bool cmp(int u,int v){
	return len[u] > len[v];
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d",&n);
 	scanf("%s%s",s+1,v+1);
 	init();
 	rep(i,1,n) ins(s[i]-'a','1'-v[i]);
 	rep(i,1,tot) num.pb(i);
 	sort(all(num),cmp);
 	for(auto x:num) siz[link[x]] += siz[x];
 	ll ans = 0;
 	rep(i,1,tot) ans = max(ans , (ll) siz[i] * len[i]);
 	printf("%lld\n",ans);
	return 0;
}