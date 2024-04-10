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
using namespace std;
int t,n,a[N],f[N],cnt[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d",&t);
 	while(t--){
 		scanf("%d",&n);
 		rep(i,1,n) f[i] = cnt[i] = 0;
 		rep(i,1,n) scanf("%d",&a[i]),cnt[a[i]]++;
 		int cut = 0;
 		rep(i,2,n){
 			if(a[i] == a[i-1]) f[a[i]] += 2,cut++;
 		}
 		f[a[1]] ++;
 		f[a[n]] ++;
 		if(*max_element(cnt+1,cnt+n+1) > (n+1)/2){
 			puts("-1");
 			continue;
 		}
 		printf("%d\n",(cut+max(*max_element(f+1,f+n+1)-(cut+2),0)));
 	}
	return 0;
}