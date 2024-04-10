#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define M 300300

int n, d[M], p, t[M];
pair<int, int> e[M];
long long ans = 0;

void read(void){
	cin >> n >> p;
	for (int i = 0, x, y; i < n; ++i){
		cin >> x >> y;
		--x;
		--y;
		if (x>y)
			swap(x, y);
		e[i] = make_pair(x, y);
		++d[x];
		++d[y];
	}
	for (int i = 0; i < n; ++i)
		t[i] = d[i];
}

void kill(void){
	sort(d, d + n);
	sort(e, e + n);
	int l = 0, r = n - 1;
	while (l < n){
		while (r >= 0 && d[l] + d[r] >= p)
			--r;
		//cout << r << "!\n";
		ans += (n - 1 - r);
		if (l>r)
			ans--;
		++l;
	}

	//cout << ans << "\n";
	ans /= 2;

	for (int i = 0, j; i < n;){
		int x = e[i].first;
		int y = e[i].second;
		j = i;
		while (j < n && e[i] == e[j])
			++j;

		if (t[x] + t[y] - (j - i) < p && t[x]+t[y]>=p)
			--ans;
		i = j;
	}

	cout << ans << "\n";
}

int main(){
#ifdef GORILLA
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#else
	ios_base::sync_with_stdio(0);
#endif

	read();
	kill();

	return 0;
}