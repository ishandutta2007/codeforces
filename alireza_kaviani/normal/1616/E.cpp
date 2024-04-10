#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)      (x).begin(),(x).end()
#define X           first
#define Y           second
#define sep         ' '
#define endl        '\n'
#define SZ(x)       ll(x.size())

const ll MAXN = 1e6 + 10;
const ll LOG = 30;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int q , n , fen[MAXN];
vector<int> vec[LOG];
string s , t;

void add(int x , int val){
	for(x++; x < MAXN ; x += x & -x)	fen[x] += val;
}

int get(int x){
	int ans = 0;
	for(x++; x > 0 ; x -= x & -x)	ans += fen[x];
	return ans;
}

ll Main(){
	if(s < t)	return 0;
	fill(fen , fen + n + 5 , 0);
	int len = 0;
	while(len < n && s[len] == t[len])	len++;
	for(int i = 1 ; i < len ; i++){
		if(s[i] < s[i - 1]){
			return 1;
		}
	}
	ll ans = INF;
	for(int i = 0 ; i < LOG ; i++){
		vec[i].clear();
	}
	for(int i = 1 ; i < n ; i++){
		add(i , 1);
	}
	for(int i = n - 1 ; i >= len ; i--){
		vec[s[i] - 97].push_back(i);
	}
	for(int i = len ; i < n && len > 0 ; i++){
		if(s[i] < t[len - 1]){
			ans = min(ans , i - len + 1ll);
		}
	}
	ll cur = 0;
	for(int i = len ; i < n ; i++){
		for(int j = 0 ; j < LOG ; j++){
			if(int(t[i] - 97) > j && SZ(vec[j]) > 0){
		//		cout << i << sep << j << sep << cur << sep << get(vec[j].back()) << endl;
				ans = min(ans , cur + get(vec[j].back()) - i);
			}
		}
		int c = int(t[i] - 97);
		if(SZ(vec[c]) == 0){
			break;
		}
		int pos = vec[c].back();
		vec[c].pop_back();
		cur += get(pos) - i;
		add(0 , 1);
		add(pos , -1);
	}
	return (ans == INF ? -1 : ans);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cin >> n >> s >> t;
		ll res = Main();
		cout << res << endl;
	}

    return 0;
}
/*

*/