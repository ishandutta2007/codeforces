#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ld eps=1e-10;
const ll inf=10000000010;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAXN = 100010;

int t, x;
ll tmp;
char ch;

map<int, int> mp;

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>t;
	while (t--){
		cin>>ch>>tmp;
		x=0;
		for (int j=1; tmp; j*=2, tmp/=10) x+=j*(tmp%2);
		if (ch=='?') cout<<mp[x]<<endl;
		if (ch=='+') mp[x]++;
		if (ch=='-') mp[x]--;
	}
	
	return 0;
}