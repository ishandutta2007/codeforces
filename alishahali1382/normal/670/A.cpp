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

int n;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	cout<<n/7*2 + max(n%7-5, 0)<<' ';
	cout<<min(n, 2 + (n-2)/7*2 + max((n-2)%7-5, 0))<<endl;
	
	return 0;
}