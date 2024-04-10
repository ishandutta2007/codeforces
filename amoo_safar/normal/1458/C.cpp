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
const int N = 1e3 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int a[N][N], b[N][N];

int n, m;
int OK(int x){
	x %= n;
	return (x + n) % n;
}
int Main(){

	cin >> n >> m;

	vector<int> p = {0, 1, 2};
	vector<int> lz = {0, 0, 0};

	int v;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> v; v--;
			a[i][j] = v;
		}
	}
	str s;
	cin >> s;
	for(auto c : s){
		if(c == 'L')
			lz[2] --;
		if(c == 'R')
			lz[2] ++;
		if(c == 'U')
			lz[1] --;
		if(c == 'D')
			lz[1] ++;
		if(c == 'I'){
			swap(p[0], p[2]);
			swap(lz[0], lz[2]);
		}
		if(c == 'C'){
			swap(p[0], p[1]);
			swap(lz[0], lz[1]);
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			vector<int> st = {a[i][j], i, j};
			b[OK(st[p[1]] + lz[1])][OK(st[p[2]] + lz[2])] = OK(st[p[0]] + lz[0]);
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << b[i][j] + 1 << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while(T --) Main();
	return 0;
}

/*

1
3 1
1 2 3
2 3 1
3 1 2
L

*/