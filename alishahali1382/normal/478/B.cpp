#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const int inf=1000000010;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 510;

ll n, m, tmp, x;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	tmp=n/m;
	x=n-tmp*m;
	cout<<tmp*(tmp-1)/2*(m-x)+tmp*(tmp+1)/2*x<<' ';
	tmp=n-m+1;
	cout<<tmp*(tmp-1)/2<<endl;
	return 0;
}