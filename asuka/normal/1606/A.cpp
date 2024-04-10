#include<bits/stdc++.h>
#define ll long long
#define N
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
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
int t, n;
char s[105];
bool check() {
	int cnt = 0;
	rep(i, 1, n - 1) {
		if(s[i] == 'a' && s[i + 1] == 'b') cnt++;
		if(s[i] == 'b' && s[i + 1] == 'a') cnt--;
	}
	return cnt == 0;
}
void solve() {
	if(check()) {
		printf("%s\n", s + 1);
		return;
	}
	rep(i, 1, n) {
		s[i] = s[i] ^ 'a' ^ 'b';
		if(check()) {
			printf("%s\n", s + 1);
			return;
		}
		s[i] = s[i] ^ 'a' ^ 'b';
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &t);
	while(t--) {
		scanf("%s", s + 1);
		n = strlen(s + 1);
		solve();
	}
	return 0;
}