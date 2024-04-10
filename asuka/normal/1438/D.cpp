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
int n,a[N];
struct node{
	int u,v,w;
	node(){}
	node(int a,int b,int c){u = a;v = b;w = c;}
};
vector<node> ans;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d",&n);
 	rep(i,1,n) scanf("%d",&a[i]);
 	if(n&1){
 		printf("YES\n");
 		printf("%d\n",n-1);
 		for(int i = 1;i+2 <= n;i += 2){
 			printf("%d %d %d\n",i,i+1,i+2);
 		}
 		for(int i = 1;i+2 <= n;i += 2){
 			printf("%d %d %d\n",i,i+1,n);
 		}
 	}else{
 		int res = 0;
 		rep(i,1,n) res ^= a[i];
 		if(res == 0){
 			printf("YES\n");
 			n--;
 			printf("%d\n",n-1);
 			for(int i = 1;i+2 <= n;i += 2){
 				printf("%d %d %d\n",i,i+1,i+2);
 			}
 			for(int i = 1;i+2 <= n;i += 2){
 				printf("%d %d %d\n",i,i+1,n);
 			}
 		}else{
 			printf("NO\n");
 		}
 	}
	return 0;
}