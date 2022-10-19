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
int n,a[100015],sum;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d",&n);
 	rep(i,1,n) scanf("%d",&a[i]),sum += a[i];
 	int bg,sm,cnt;
 	if(sum % n == 0) bg = sm = sum / n,cnt = 0;
 	else cnt = sum % n,bg = sum/n+1,sm = sum/n;
 	sort(a+1,a+n+1); reverse(a+1,a+n+1);
 	int ans = 0;
 	rep(i,1,cnt) ans += abs(a[i] - bg);
 	rep(i,cnt+1,n) ans += abs(a[i] - sm);
//  	assert(ans%2==0);
 	printf("%d\n",ans/2);
	return 0;
}