#include <bits/stdc++.h>

using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define sqr(a) ((a) * (a))
#define endl "\n"
#define mod % 1000000007
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
typedef long double ld;
typedef map<int, int>::iterator mit;
const ld E = 1e-4;
const int MOD = 1e9 + 7;

#ifdef LOCAL
const ll MAX = 1e3;
//#define DEBUG
#else
const ll MAX = 1e5;
#endif

int t[MAX];
vector<int> vec[MAX];
bool used[MAX];
queue<int> q;

int dfs(int pos){
	int ans = 1;
	used[pos] = true;
	if(t[pos] == 0)
		q.push(pos);
	for(int i = 0; i < (int) vec[pos].size(); i++)
		if(!used[vec[pos][i]])
			ans += dfs(vec[pos][i]);
	return ans;
}

bool update(int size){
	while(!q.empty()){
		int pos = q.front();
		q.pop();
		size--;
		for(int i = 0; i < (int) vec[pos].size(); i++)
			if(--t[vec[pos][i]] == 0)
				q.push(vec[pos][i]);
	}
	return (!size);
}

int main() {

	sync;
	cout.precision(20);

#ifdef LOCAL
	srand(time(NULL));
	input;
#else

#endif

	int n, m;
	cin >> n >> m;
	ms(t);

	while(m--){
		int a, b;
		cin >> a >> b;
		a--, b--;
		vec[a].push_back(b);
		vec[b].push_back(a);
		t[b]++;
	}

	ms(used);

	int ans = n;

	for(int i = 0; i < n; i++)
		if(!used[i] && update(dfs(i)))
			ans--;

	cout << ans;

}