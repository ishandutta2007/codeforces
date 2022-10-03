#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const int inf=1000000010;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 300010;

int n, k, x, y, xx, yy;
ld ans;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k>>x>>y;
	for (int i=1; i<n; i++){
		cin>>xx>>yy;
		ans+=sqrt((x-xx)*(x-xx) + (y-yy)*(y-yy));
		x=xx;
		y=yy;
	}
	ans=ans*k/50;
	cout<<setprecision(10)<<fixed<<ans<<endl;
	return 0;
}