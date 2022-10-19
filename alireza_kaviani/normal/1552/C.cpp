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

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int q , n , k , mark[MAXN] , match[MAXN] , fen[MAXN];

void add(int x , int v){
	for( ; x < MAXN ; x += x & -x)	fen[x] += v;
}

int get(int x){
	int ans = 0;
	for( ; x ; x -= x & -x)	ans += fen[x];
	return ans;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cin >> n >> k;
		fill(mark , mark + n + n + 10 , 0);
		vector<pii> vec;
		for(int i = 0 ; i < k ; i++){
			int x , y;
			cin >> x >> y;
			if(x > y)	swap(x , y);
			vec.push_back({x , y});
			mark[x] = mark[y] = 1;
		}
		vec.resize(n);
		int x = k , y = k;
		for(int i = 1 ; i <= n + n ; i++){
			if(mark[i])	continue;
			if(x < n){
				vec[x].X = i;
				x++;
			}
			else{
				vec[y].Y = i;
				y++;
			}
		}
		/*for(int i = 0 ; i < n ; i++){
			cout << vec[i].X << sep << vec[i].Y << endl;
		}*/
		sort(all(vec));
		int ans = 0;
		for(int i = 0 ; i < n ; i++){
			for(int j = i + 1 ; j < n ; j++){
				if(vec[j].X < vec[i].Y && vec[i].Y < vec[j].Y)	ans++;
			}
		}
		cout << ans << endl;
	}

    return 0;
}
/*

*/