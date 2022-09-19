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

int a[N];

int Main(){
	int n, m;
	cin >> n >> m;
	str s;
	cin >> s;
	int fl = 0;
	for(int i = 1; i <= m; i++){
		fl = 0;
		str t = s;
		for(int j = 0; j < n; j++){
			if(t[j] == '1') continue;
			int cnt = 0;
			if(j + 1 < n && t[j + 1] == '1') cnt ++;
			if(j > 0 && t[j - 1] == '1') cnt ++;
			if(cnt == 1)
				s[j] = '1', fl = 1;
		}
		if(!fl) break;
	}
	cout << s << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	cin >> T;
	while(T --) Main();
	return 0;
}