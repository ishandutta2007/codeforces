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

const ll MAXN = 5010;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , k , trieInd , valid[MAXN][MAXN] , nxt[MAXN * MAXN / 2][2] , cnt[MAXN * MAXN / 2];
string s , ans;

void DFS(int v){
	k -= cnt[v];
	if(k <= 0){
		cout << ans << endl;
		exit(0);
	}
	for(int i = 0 ; i < 2 ; i++){
		if(nxt[v][i] == 0)	continue;
		char c = (i == 0 ? 'a' : 'b');
		ans.push_back(c);
		DFS(nxt[v][i]);
		ans.pop_back();
	}
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> s >> k; n = SZ(s);
	for(int i = 0 ; i < MAXN ; i++){
		for(int j = 0 ; j < i ; j++){
			valid[i][j] = 1;
		}
	}
	for(int l = n - 1 ; l >= 0 ; l--){
		for(int r = l ; r < n ; r++){
			if(s[l] == s[r]){
				valid[l][r] = (r < 2 ? 1 : valid[l + 2][r - 2]);
			}
		}
	}

	for(int i = 0 ; i < n ; i++){
		int cur = 0;
		for(int j = i ; j < n ; j++){
			int c = (s[j] == 'a' ? 0 : 1);
			if(nxt[cur][c] == 0)	nxt[cur][c] = ++trieInd;
			cur = nxt[cur][c];
			if(valid[i][j]){
				cnt[cur]++;
			}
		}
	}
	DFS(0);

    return 0;
}
/*

*/