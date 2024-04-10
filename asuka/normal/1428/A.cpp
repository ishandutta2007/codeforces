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
using namespace std;
int t,a1,b1,a2,b2;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d",&t);
 	while(t--){
 		scanf("%d%d%d%d",&a1,&b1,&a2,&b2);
 		int d1 = abs(a1-a2),d2 = abs(b1-b2),d3 = 0;
 		if(d1 != 0 && d2 != 0) d3 = 2;
 		printf("%d\n",d1+d2+d3);
 	}
	return 0;
}