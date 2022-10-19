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
using namespace std;
int t,n;
char s[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d",&t);
 	while(t--){
 		int c1 = 0,c2 = 0;
 		scanf("%d",&n); scanf("%s",s+1);
 		rep(i,2,n){
 			if(s[i]=='0'&&s[i-1]=='0') c1++;
 			if(s[i]=='1'&&s[i-1]=='1') c2++;
 		}
 		printf("%d\n",max(c1,c2));
 	}
	return 0;
}