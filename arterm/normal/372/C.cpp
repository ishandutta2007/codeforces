#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

#define M 300300
#define long long long

long n, m, l, r;
long p[M], d[M], ans=0, q[M], di;

void add(long x){
	q[r] = x;
	while (r > l && p[q[r]] > p[q[r - 1]]){
		q[r - 1] = q[r];
		--r;
	}
	++r;
}

void del(long x){
	while (q[l] < x && l<r)
		++l;
}

long ma(void){
	return p[q[l]];
}

void upd(long a, long t){
	l = 0, r = 0;
	long de = t*di;
	for (long i = 1; i <= 1 + de && i <= n; ++i)
		add(i);

	long re = min(n*1ll, 1 + de);

	for (long i = 1; i <= n; ++i){
		del(i - de);

		if (re < n && re < i + de)
			add(++re);

		d[i] = ma() - abs(a - i);
	}

	for (long i = 1; i <= n; ++i)
		p[i] = d[i];
}

void read(void){
	cin >> n >> m >> di;
	long a, b, t, tl = 0;
	for (long i = 0; i < m; ++i){
		cin >> a >> b >> t;
		ans += b;

		upd(a, t - tl);

		tl = t;
	}

	cout << ans + *max_element(p + 1, p + (n + 1))<<"\n";
}



int main(){
#ifdef TROLL
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#else
	ios_base::sync_with_stdio(0);
#endif

	read();


	return 0;
}