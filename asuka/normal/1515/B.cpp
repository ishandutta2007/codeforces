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
int t,n;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d",&t);
 	while(t--){
 		scanf("%d",&n);
 		if(n == 1) puts("NO");
 		else{
 			if(n == 2 || n == 4) puts("YES");
 			else{
 				int sq = sqrt(n),qs = sqrt(n/2);
 				if(sq*sq == n && n%4 == 0) puts("YES");
 				else if(n%2 == 0 && qs*qs == (n/2)) puts("YES");
 				else puts("NO");
 			}
 		}
 	}
	return 0;
}