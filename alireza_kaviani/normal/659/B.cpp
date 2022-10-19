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
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , m;
string s[MAXN];
vector<pii> vec[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> m;
	for(int i = 0 ; i < n ; i++){
		int group , score;
		cin >> s[i] >> group >> score;
		vec[group].push_back({score , i});
	}
	for(int i = 1 ; i <= m ; i++){
		sort(all(vec[i]) , greater<pii>());
		if(SZ(vec[i]) > 2 && vec[i][1].X == vec[i][2].X){
			cout << "?" << endl;
			continue;
		}
		cout << s[vec[i][0].Y] << sep << s[vec[i][1].Y] << endl;
	}

    return 0;
}
/*

*/