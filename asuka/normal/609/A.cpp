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
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
int n,m,a[100005],ans;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d%d",&n,&m);
 	rep(i,1,n) scanf("%d",&a[i]);
 	sort(a+1,a+n+1);
 	per(i,1,n){
 		if(m > 0) m -= a[i],ans++;
 	}
 	printf("%d\n",ans);
	return 0;
}