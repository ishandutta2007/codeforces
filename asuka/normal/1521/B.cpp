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
int t,n,a[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		rep(i,1,n) scanf("%d",&a[i]);
		int pos = min_element(a+1,a+n+1)-a;
		printf("%d\n",n-1);
		per(i,1,pos-1){
			printf("%d %d %d %d\n",i,pos,a[i+1]+1,a[pos]);
			a[i] = a[i+1]+1;
		}
		rep(i,pos+1,n){
			printf("%d %d %d %d\n",pos,i,a[pos],a[i-1]+1);
			a[i] = a[i-1]+1;
		}
	}
	return 0;
}