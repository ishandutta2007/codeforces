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

int q , n , m , k[MAXN] , cnt[MAXN] , cnt2[MAXN];
vector<int> vec[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cin >> n >> m;
		fill(cnt , cnt + n + 5 , 0);
		fill(cnt2 , cnt2 + n + 5 , 0);
		fill(vec , vec + m + 5 , vector<int>());
		for(int i = 0 ; i < m ; i++){
			cin >> k[i];
			for(int j = 0 ; j < k[i] ; j++){
				int x; cin >> x;
				vec[i].push_back(x); cnt[x]++;
			}
			if(k[i] == 1)	cnt2[vec[i][0]]++;
		}
		int flag = 0 , x = 1;
		for(int i = 1 ; i <= n ; i++){
			if(cnt2[i] > (m + 1) / 2)	flag = 1;
			if(cnt[i] >= (m + 1) / 2)	x = i;
		}
		if(flag){
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
		cnt[x] = (m + 1) / 2 - cnt2[x];
		for(int i = 0 ; i < m ; i++){
			if(SZ(vec[i]) == 1){
				cout << vec[i][0] << sep;
				continue;
			}
			int flag = 0;
			for(int j : vec[i]){
				if(cnt[x] > 0 && j == x){
					flag = 1; cnt[x]--;
					cout << x << sep;
					break;
				}
			}
			if(flag)	continue;
			for(int j : vec[i]){
				if(j != x){
					cout << j << sep;
					break;
				}
			}
		}
		cout << endl;
	}

    return 0;
}
/*

*/