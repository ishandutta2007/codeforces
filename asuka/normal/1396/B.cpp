#include<bits/stdc++.h>
#define ll long long
#define N 105
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define fi first
#define se second
using namespace std;
int t,n,a[N],T,HL;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d",&t);
 	while(t--){
 		scanf("%d",&n);
 		rep(i,1,n) scanf("%d",&a[i]);
 		int sum = accumulate(a+1,a+n+1,0),Max = *max_element(a+1,a+n+1);
 		if(Max * 2 > sum) puts("T");
 		else{
 			if(sum&1) puts("T");
 			else puts("HL");
 		}
 	}
	return 0;
}