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

const ll MAXN = 2e5 + 10;
const ll SQ = 450;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , q , x[MAXN] , y[MAXN] , ptr[MAXN] , st[MAXN] , ps[MAXN] , ans[SQ][SQ];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> q;
	for(int i = 1 ; i <= n ; i++){
		cin >> x[i] >> y[i];
	}
	for(int i = 0 ; i < q ; i++){
		int type , k , val , cost;
		cin >> type >> k; val = x[k] + y[k];
		cost = (type == 1 ? 1 : -1);
		if(type == 1){
			st[k] = i;
		}
		if(val < SQ){
			int stk = st[k] % val;
			for(int j = 0 ; j < val ; j++){
				int diff = j - stk;
				if(diff < 0)	diff += val;
				if(diff >= x[k]){
					ans[val][j] += cost;
				}
			}
		}
		else{
			for(int j = st[k] ; j < MAXN ; j += val){
				if(j + x[k] < MAXN && j + x[k] >= i)	ps[j + x[k]] += cost;
				if(j + val < MAXN && j + val >= i)		ps[j + val] -= cost;
			}
			if(type == 2 && (i - st[k] - 1) % val >= x[k])	ps[i]--;
		}
		if(i > 0)	ps[i] += ps[i - 1];
		ll res = ps[i];
		for(int j = 1 ; j < SQ ; j++){
			res += ans[j][ptr[j]];
			ptr[j]++;
			if(ptr[j] == j){
				ptr[j] = 0;
			}
		}
		cout << res << endl;
	}

    return 0;
}
/*

*/