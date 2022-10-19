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
int t,n;
bool vis[N];
char s[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d",&t);
 	while(t--){
 		int c1,c2;c1 = c2 = 0;
 		int ans = 0;
 		scanf("%d",&n);
 		scanf("%s",s+1);
 		rep(i,1,n){
 			vis[i] = 0;
 			if(s[i] == '<') c1++;
 			if(s[i] == '>') c2++;
 		}
 		rep(i,1,n){
 			if(s[i] == '-') vis[i] = vis[i%n+1] = 1;
 		}
 		rep(i,1,n) if(vis[i]) ans++;
 		if(c1 == 0||c2 == 0) printf("%d\n",n);
 		else printf("%d\n",ans);
 	}
	return 0;
}