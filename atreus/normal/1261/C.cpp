#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3000 + 10;

int adjx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int adjy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int n, m;
string s[maxn], ans[maxn];
vector<int> dp[maxn];
vector<int> a[maxn], b[maxn];
int deq[1000000 + 3000];

bool check(int x){
	for (int i = 0; i < n; i++){
		int tail = 0, head = -1;
		for (int j = 0; j < m; j++){
			while (tail <= head and dp[i][deq[head]] <= dp[i][j])
				head --;
			if (tail <= head and deq[tail] + 2 * x < j)
				tail ++;
			deq[++ head] = j;
			a[i][j] = dp[i][deq[tail]];
		}
	}
	for (int j = 0; j < m; j++){
		int tail = 0, head = -1;
		for (int i = 0; i < n; i++){
			while (tail <= head and a[deq[head]][j] <= a[i][j])
				head --;
			if (tail <= head and deq[tail] + 2 * x < i)
				tail ++;
			deq[++ head] = i;
			b[i][j] = a[deq[tail]][j];
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (s[i][j] == 'X')
				if (b[i + x][j + x] <= x)
					return 0;
	return 1;
}

bool valid(int l, int m, int r){
	return l <= m and m < r;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	int lo = 0, hi = min(n, m) + 1;
	for (int i = 0; i < n; i++){
		string t;
		cin >> t;
		if (n <= m)
			s[i] = t;
		else
			for (int j = 0; j < m; j++)
				s[j].push_back(t[j]);
	}
	bool Swaped = (n > m);
	if (n > m)
		swap(n, m);
	for (int i = n; i < 2 * n; i++)
		s[i] = s[i - n];
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++)
			s[i][j] = '.';
		s[i + 2 * n] = s[i];
	}
	n *= 3;
	string t;
	for (int i = 0; i < m; i++)
		t.push_back('.');
	for (int i = 0; i < n; i++)
		s[i] = (t + s[i]) + t;
	m *= 3;
	queue <pair<int, int> > Q;
	for (int i = 0; i < n; i++){
		dp[i].resize(m);
		for (int j = 0; j < m; j++){
			dp[i][j] = -1;
			if (s[i][j] == '.'){
				dp[i][j] = 0;
				Q.push({i, j});
			}
		}
	}
	while (!Q.empty()){
		auto it = Q.front();
		Q.pop();
		int i = it.first, j = it.second;
		for (int z = 0; z < 8; z++){
			int newi = i + adjx[z], newj = j + adjy[z];
			if (!valid(0, newi, n) or !valid(0, newj, m))
				continue;
			if (dp[newi][newj] == -1){
				dp[newi][newj] = dp[i][j] + 1;
				Q.push({newi, newj});
			}
		}
	}
	for (int i = 0; i < n; i++){
		a[i].resize(m);
		b[i].resize(m);
	}
	while (hi - lo > 1){
		int mid = (lo + hi) >> 1;
		if (check(mid))
			lo = mid;
		else
			hi = mid;
	}
	cout << lo << endl;
	n /= 3, m /= 3;
	for (int i = 0; i < n; i++)
		ans[i].resize(m);
	for (int i = n; i < 2 * n; i++){
		for (int j = m; j < 2 * m; j++){
			char me = '.';
			if (dp[i][j] > lo)
				me = 'X';
			ans[i - n][j - m] = me;
		}
	}
	if (Swaped){
		for (int j = 0; j < m; j++){
			for (int i = 0; i < n; i++)
				cout << ans[i][j];
			cout << '\n';
		}
	}
	else{
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++)
				cout << ans[i][j];
			cout << '\n';
		}
	}
}