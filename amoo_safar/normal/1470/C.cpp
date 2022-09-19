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

int n, k;

int a[N], b[N];

void Move(){
	memset(b, 0, sizeof b);
	b[1] = a[0];
	for(int i = 1; i < n; i++)
		b[(i + 1) % n] += (a[i] + 1) / 2;
	for(int i = 1; i < n; i++)
		b[(i - 1 + n) % n] += (a[i]) / 2;
	memcpy(a, b, sizeof b);
	return ;
}
vector<int> can, cn2;
int OK(int x){
	x %= n;
	return (x + n) % n;
}
void Ask(int pos){
	cout << "? " << pos + 1 << endl;
	int res;
	cin >> res;
	// res = a[OK(pos - 3)];
	cn2.clear();
	for(auto x : can){
		if(a[OK(pos - x)] == res)
			cn2.pb(x);
	}
	can = cn2;
	return ;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	srand(time(0));

	cin >> n >> k;
	fill(a, a + n, k);
	int nw = 0;
	for(int i = 0; i < n; i++) can.pb(i);

for(int i = 0; i < 500; i++){
		Ask(nw);
		Move();
		nw = OK(nw + i);
	}
	
	while((int) can.size() > 1){
		int fs = can[0], sc = can[1];
		int q = -1;

		for(int i = 0; i < n; i++){
			if(a[OK(i - fs)] != a[OK(i - sc)])
				q = i;
		}
		if(q == -1)
			q = rand() % n;
		Ask(q);
		Move();
	}
	// debug(can.size());
	cout << "! " << can[0] + 1 << endl;
	return 0;
}