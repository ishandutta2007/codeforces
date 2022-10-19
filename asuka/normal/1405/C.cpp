#include<bits/stdc++.h>
#define ll long long
#define N 300015
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
using namespace std;
int t,n,k,val[N];
char s[N];
void solve(){
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
    rep(i,1,n-k) if (s[i]!='?' && s[i+k]!='?' && s[i]!=s[i+k]) {puts("NO"); return;}
    rep(i,1,n-k) if (s[i]!='?' && s[i+k]=='?') s[i+k]=s[i];
    per(i,k+1,n) if (s[i]!='?' && s[i-k]=='?') s[i-k]=s[i];
    rep(i,1,n-k) if (s[i]!='?' && s[i+k]!='?' && s[i]!=s[i+k]) {puts("NO"); return;}
	int s1 = 0,s2 = 0;
	rep(i,1,k){
		if(s[i] == '0') s1++;
		if(s[i] == '1') s2++;
	}
	if(s1> k/2||s2 > k/2){
		puts("NO");
		return;
	}
	// rep(i,k+1,n){
	// 	if(s[i-k] == '0') sum++;
	// 	if(s[i-k] == '1') sum--;
	// 	if(s[i] == '0') sum--;
	// 	if(s[i] == '1') sum++;
	// 	if(sum > k/2||sum < -k/2){
	// 		puts("NO");
	// 		return;
	// 	}
	// }
	puts("YES");
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d",&t);
 	while(t--){
 		solve();
 	}
	return 0;
}