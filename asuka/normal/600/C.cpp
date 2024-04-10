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
#define SZ(x) ((int)x.size())
using namespace std;
char s[N];
int cnt[26],n;
VI odd;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%s",s+1);
 	n = strlen(s+1);
 	rep(i,1,n) cnt[s[i]-'a']++;
 	rep(i,0,25) if(cnt[i]&1) odd.pb(i);
 	int sz = SZ(odd)/2;
 	rep(i,0,sz-1) cnt[odd[i]]++;
 	rep(i,0,sz-1) cnt[odd[SZ(odd)-i-1]]--;
 	string ans;
 	rep(i,0,25) rep(j,1,cnt[i]/2) ans += i+'a';
 	cout << ans;
 	rep(i,0,25) if(cnt[i]&1) cout << (char)(i+'a');
 	reverse(all(ans));
 	cout << ans;
	return 0;
}