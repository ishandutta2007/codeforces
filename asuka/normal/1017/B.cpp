#include<bits/stdc++.h>
#define ll long long
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
const int N = 100015;
int n;
char s[N], t[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%s%s", &n, s + 1, t + 1);
	int c1, c2, c3, c4;
	c1 = c2 = c3 = c4 = 0;
	rep(i, 1, n) {
		if(s[i] == '0') c1++;
		else c2++;
		if(s[i] == '1' && t[i] == '1') c3++;
		if(s[i] == '0' && t[i] == '1') c4++;
	}
	printf("%lld\n", (ll) c1 * c2 - (ll) c3 * c4);
	return 0;
}