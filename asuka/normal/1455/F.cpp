#include<bits/stdc++.h>
#define ll long long
#define N 505
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
string dp[N];
char s[N];
int ta,na,ka;
char inc(char c){
	return (c-'a'+1)%ka+'a';
}
char dec(char c){
	return (c-'a'+ka-1)%ka+'a';
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&ta);
	while(ta--){
		scanf("%d%d",&na,&ka);
		scanf("%s",s+1);
		dp[0] = "";
		rep(i,1,na) dp[i] = dp[i-1]+'z';
		rep(i,0,na-1){
			if(i<1) dp[i+1] = min({dp[i+1],
				dp[i]+inc(s[i+1]),
				dp[i]+dec(s[i+1]),
				dp[i]+s[i+1]});
			else dp[i+1] = min({dp[i+1],
				dp[i].substr(0,i-1)+s[i+1]+dp[i].back(),
				dp[i]+inc(s[i+1]),
				dp[i]+dec(s[i+1]),
				dp[i]+s[i+1]});
			if(i+2 <= na){
				if(i<1) dp[i+2] = min({dp[i+2],
					dp[i]+inc(s[i+2])+s[i+1],
					dp[i]+dec(s[i+2])+s[i+1]});
				else dp[i+2] = min({dp[i+2],
					dp[i]+inc(s[i+2])+s[i+1],
					dp[i]+dec(s[i+2])+s[i+1],
					dp[i].substr(0,i-1)+s[i+2]+dp[i].back()+s[i+1]});
			}
			// cout << dp[i] << endl;
		}
		rep(i,1,na) s[i] = dp[na][i-1];
		printf("%s\n",s+1);
	}
	return 0;
}
/*
1
5 7
eabba
*/