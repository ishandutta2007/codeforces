#include <iostream>

using namespace std;

#define long long long
#define M 100100

long a[M], len = 1, m, n,q[M];
long t[M], l[M], c[M], e[M], s[M];

void read(void){
	cin >> m;
	for (long i = 0; i < m; ++i){
		cin >> t[i];
		if (t[i] == 1)
			cin >> e[i], s[i] = 1;
		else
			cin >> l[i] >> c[i], s[i] = l[i] * c[i];

		if (len < M){
			if (t[i] == 1)
				a[len++] = e[i];
			else
			for (int j = 0; j < c[i] && len<M; ++j)
			for (int k = 1; k <= l[i] && len < M; ++len, ++k)
				a[len] = a[k];
		}
	}

	long c = 0, pos=0,st=0;

	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> pos;
		while (c + s[st] < pos)
			c += s[st], st++;
		if (t[st] == 1)
			cout << e[st] << " ";
		else
			cout << a[(pos - c - 1) % l[st]+1] << " ";
	}
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