#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define P 111
#define N 1511000
#define INF 2000000000000000000ll

#define long long long

long n, m, b;
long d[N], e[N], h[P], k[P], x[P];
int p[P];

void pre(void){
	p[0] = 1;
	for (int i = 1; i < P; ++i)
		p[i] = 2 * p[i - 1];
}

void read(void){
	cin >> n >> m >> b;

	for (int i = 1, t; i <= n; ++i){
		cin >> x[i] >> k[i] >> t;

		for (int j = 0, l; j < t; ++j){
			cin >> l;
			--l;
			h[i] ^= p[l];
		}
	}

	for (int i = 1; i <= n; ++i)
	for (int j = i + 1; j <= n; ++j)
	if (k[i]>k[j]){
		swap(k[i], k[j]);
		swap(h[i], h[j]);
		swap(x[i], x[j]);
	}
}

void din(void){
	d[0] = 0;
	for (int i = 1; i < p[m]; ++i)
		d[i] = INF;

	long ans = INF;

	for (int i = 1; i <= n; ++i){

		for (int j = 0; j < p[m]; ++j)
			e[j] = d[j];

		for (int j = 0; j < p[m]; ++j)
			e[j | h[i]] = min(e[j | h[i]], d[j] + x[i]);

		for (int j = 0; j < p[m]; ++j)
			d[j] = e[j];

		if (d[p[m]-1]<INF)
		ans = min(ans, d[p[m] - 1] + b*k[i]);
	}


	if (ans == INF)
		cout << "-1\n";
	else
		cout << ans << "\n";
}


int main(){
#ifdef GORILLA
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#else
	ios_base::sync_with_stdio(0);
#endif

	pre();

	read();

	din();



	return 0;
}