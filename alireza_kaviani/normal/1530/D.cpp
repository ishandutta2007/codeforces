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

int q , n , A[MAXN] , ans[MAXN] , mark[MAXN];
vector<int> ind[MAXN];

void Kill(int x , int y){
	int cnt = 0 , flag = 0;
	for(int i = 1 ; i <= n ; i++){
		if(ans[i] == A[i])	cnt++;
		if(ans[i] == i)	flag = 1;
	}
	if(flag)	swap(ans[x] , ans[y]);
	cout << cnt << endl;
	for(int i = 1 ; i <= n ; i++){
		cout << ans[i] << sep;
	}
	cout << endl;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cin >> n;
		fill(ans , ans + n + 5 , 0);
		fill(mark , mark + n + 5 , 0);
		fill(ind , ind + n + 5 , vector<int>());
		for(int i = 1 ; i <= n ; i++){
			cin >> A[i];
			ind[A[i]].push_back(i);
		}
		int x = -1 , y = -1;
		vector<int> vec;
		for(int i = 1 ; i <= n ; i++){
			if(SZ(ind[i]) > 1){
				x = ind[i][0]; y = ind[i][1];
			}
			if(SZ(ind[i])){
				ans[ind[i].back()] = i;
				ind[i].pop_back();
				mark[i] = 1;
			}
			for(int j : ind[i]){
				vec.push_back(j);
			}
		}
		for(int i = 1 ; i <= n ; i++){
			if(ans[i] == 0 && mark[i] == 0){
				ans[i] = i;
				mark[i] = 1;
			}
		}
		for(int i = 1 , ptr = 1 ; i <= n ; i++){
			if(ans[i] != 0)	continue;
			while(mark[ptr])	ptr++;
			ans[i] = ptr;
			mark[ptr] = 1;
		}
		if(SZ(vec) <= 1){
			Kill(x , y);
			continue;
		}
		int F = ans[vec[0]];
		for(int i = 0 ; i + 1 < SZ(vec) ; i++){
			ans[vec[i]] = ans[vec[i + 1]];
		}
		ans[vec.back()] = F;
		Kill(x , y);
	}

    return 0;
}
/*

*/