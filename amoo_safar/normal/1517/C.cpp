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

int ans[N][N];
int p[N];
int iv[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> p[i];
		iv[p[i]] = i;
	}
	for(int i = 1; i <= n; i++){
		int x = iv[i], y = iv[i];
		ans[x][y] = i;
		for(int j = 1; j < i; j++){
			if(iv[j] < iv[i]) y--;
			else x ++;
			ans[x][y] = i;
		}
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= i; j++)
			cout << ans[i][j] << " \n"[j == i];
	return 0;
}