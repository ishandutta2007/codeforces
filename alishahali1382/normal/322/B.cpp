#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const ll inf=1000000010;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 200010;

ll a, b, c, s, ss, tmp, ans;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%lld %lld %lld", &a, &b, &c);
	for (int tmp=0; tmp<=min(min(a, min(b, c)), 2LL); tmp++) ans=max(ans, (a-tmp)/3 + (b-tmp)/3 + (c-tmp)/3 + tmp);
	cout<<ans<<endl;
	
	return 0;
}