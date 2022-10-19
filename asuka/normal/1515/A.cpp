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
int T,n,a[1005],x;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d",&T);
 	while(T--){
 		scanf("%d%d",&n,&x);
 		rep(i,1,n) scanf("%d",&a[i]);
 		sort(a+1,a+n+1);
 		bool flag = 1;
 		int sum = 0;
 		rep(i,1,n) {
 			sum += a[i];
 			if(sum == x){
 				if(i == n){
 					flag = 0;
 				}
 				sum -= a[i]; sum += a[i+1];
 				swap(a[i],a[i+1]);
 			}
 		}
 		if(flag){
 			puts("YES");
 			rep(i,1,n) printf("%d ",a[i]);
 			printf("\n");
 		}else{
 			puts("NO");
 		}
 	}
	return 0;
}