// vaziat meshki-ghermeze !
#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1000000007LL;
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int a[N];
int n;

vector<int> V;
void Do(int i){
	int x = a[i] ^ a[i + 1] ^ a[i + 2];
	a[i] = a[i + 1] = a[i + 2] = x;
	V.pb(i);
}
int Main(){
	cin >> n;
	V.clear();

	int sm = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		sm += a[i];
	}
	if(sm % 2 == 1) return cout << "NO\n", 0;
	if(a[1] == 0){
		
	} else {
		int idx = -1;
		for(int i = 2; i + 1 <= n; i += 2){
			if(a[i] != a[i + 1]){
				idx = i;
				break;
			}
		}
		if(idx == -1) return cout << "NO\n", 0;
		for(int i = idx - 1; i >= 1; i -= 2)
			Do(i);
	}
	for(int i = 1; i <= n; i++){
		if(i == n) break;
		if(a[i + 1] == 0) continue;
		if(a[i + 2] == 1){
			Do(i);
			continue;
		}
		assert(i + 3 <= n);
		Do(i + 1);
		Do(i);
	}
	cout << "YES\n" << V.size() << '\n';
	for(auto x : V) cout << x << ' ';
	cout << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc = 1;
	cin >> tc;
	while(tc --) Main();
	return 0;
}