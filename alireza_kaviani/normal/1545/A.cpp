#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)						(x).begin(),(x).end()
#define X							first
#define Y							second
#define sep							' '
#define endl						'\n'
#define SZ(x)						ll(x.size())

const ll MAXN = 1e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int q , n , A[MAXN] , fen[MAXN] , odd[MAXN] , even[MAXN] , cnt[MAXN];

void add(int x , int v){
	for(x++; x < MAXN ; x += x & -x)	fen[x] += v;
}

int get(int x){
	int ans = 0;
	for(x++; x > 0 ; x -= x & -x)	ans += fen[x];
	return ans;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		fill(fen , fen + MAXN , 0);
		fill(cnt , cnt + MAXN , 0);
		fill(odd , odd + MAXN , 0);
		fill(even , even + MAXN , 0);
		cin >> n;
		vector<pii> vec;
		for(int i = 0 ; i < n ; i++){
			cin >> A[i];
			vec.push_back({A[i] , i});
		}
		sort(all(vec));
		for(int i = 0 ; i < n ; i++){
			cnt[vec[i].X]++;
			if(vec[i].Y % 2 != i % 2){
				if(cnt[vec[i].X] & 1)	odd[vec[i].X]++;
				else	even[vec[i].X]++;
			}
		}
		int flag = 0;
		for(int i = 0 ; i < MAXN ; i++){
			if(even[i] != odd[i])	flag = 1;
		}
		cout << (flag ? "NO" : "YES") << endl;
	}

    return 0;
}
/*

*/