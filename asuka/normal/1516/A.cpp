#include<bits/stdc++.h>
#define ll long long
#define N 205
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
int T,n,k,a[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d",&T);
 	while(T--){
 		scanf("%d%d",&n,&k);
 		rep(i,1,n) scanf("%d",&a[i]);
 		int l = 1;
 		while(k && l < n){
 			if(a[l] == 0) l++;
 			else a[n]++,a[l]--,k--;
 		}
 		rep(i,1,n) printf("%d ",a[i]);
 		printf("\n");
 	}
	return 0;
}