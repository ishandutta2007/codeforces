#include<bits/stdc++.h>
#define ll long long
#define N 300015
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
int t,n,l[N],r[N],ans[N];
char s[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d",&t);
 	s[0] = '$'; // ccf
 	rep(_,1,t){
 		scanf("%d",&n); scanf("%s",s+1);
 		rep(i,1,n) l[i] = r[i] = 1;
 		rep(i,2,n) l[i] = s[i]!=s[i-1]?l[i-1]+1:1;
 		per(i,1,n-1) r[i] = s[i]!=s[i+1]?r[i+1]+1:1;
 		rep(i,1,n+1){
 			ans[i] = 1;
 			if(s[i-1] == 'L') ans[i] += l[i-1];
 			if(s[i] == 'R') ans[i] += r[i];
 		}
 		rep(i,1,n+1) printf("%d ",ans[i]); printf("\n");
 	}
	return 0;
}