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
int t,n;
bool isprime(int x){
	if(x == 2) return 1;
	for(int i = 2;i*i <= x;++i){
		if(x%i==0) return 0;
	}
	return 1;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d",&t);
 	while(t--){
 		scanf("%d",&n);
 		int x = 2;
 		while(!isprime(x+n-1)||isprime(x)) x++;
 		rep(i,1,n){
 			rep(j,1,n){
 				if(i == j) printf("%d ",x);
 				else printf("1 ");
 			}
 			puts("");
 		}
 	}
	return 0;
}