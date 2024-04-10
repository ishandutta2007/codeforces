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
using namespace std;
int t,n,a[N],pa[N],dep[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d",&t);
 	while(t--){
 		scanf("%d",&n);int ans = 0;
 		rep(i,1,n) scanf("%d",&a[i]);
 		int fa = 1;
 		dep[1] = 0;
 		rep(i,2,n){
 			if(a[i] > a[i-1]) pa[i] = fa;
 			else fa++,pa[i] = fa;
 			//cout << i << ' ' << pa[i] << endl;
 		}
 		rep(i,2,n) dep[i] = dep[pa[i]]+1,ans = max(ans,dep[i]);//,cout << dep[i]<< ' '; cout<<endl;
 		printf("%d\n",ans);
 	}
	return 0;
}