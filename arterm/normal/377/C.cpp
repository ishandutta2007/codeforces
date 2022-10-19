#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define M 2000000
#define N 22
#define INF 1000000000

int d[N][M], s[10 * N], p[N];
int n, m;
char a[N];
int x[N];
bool u[N][M];
vector<int> bucket[N];

int sum(int x){
	int s = 0;
	while (x){
		s += x & 1;
		x >>= 1;
	}
	return s;
}

void pre(void){
	p[0] = 1;
	for (int i = 1; i<N; ++i)
		p[i] = 2 * p[i - 1];
}

void din(void){
	for (int i = 0; i < p[m]; ++i)
		bucket[sum(i)].push_back(i);

	for (int i = m-1; i >= 0; --i)
	for (int j = 0; j < (int)bucket[i].size(); ++j){
		int mask = bucket[i][j];
		int ans = x[i] == 1 ? -INF : INF;

		if (a[i] == 'p'){

			if (x[i] == 1){
				for (int k = 0; k<m; ++k)
				if ((mask&p[k]) == 0)
					ans = max(ans, d[i + 1][mask^p[k]] + s[k]);
			}
			else{
				for (int k = 0; k<m; ++k)
				if ((mask&p[k]) == 0)
					ans = min(ans, d[i + 1][mask^p[k]] - s[k]);
			}

		}
		else{

			if (x[i] == 1){
				for (int k = 0; k<m; ++k)
				if ((mask&p[k]) == 0)
					ans = max(ans, d[i + 1][mask^p[k]]);
			}
			else{
				for (int k = 0; k<m; ++k)
				if ((mask&p[k]) == 0)
					ans = min(ans, d[i + 1][mask^p[k]]);
			}

		}

		d[i][mask] = ans;
	}
}

void read(void){
	cin >> n;

	for (int i = 0; i<n; ++i)
		cin >> s[i];

	cin >> m;

	sort(s, s + n);
	reverse(s, s + n);

	for (int j = 0; j<m; ++j)
		cin >> a[j] >> x[j];

	n = m;
}


int main()
{
	pre();
	read();
	din();
	cout << d[0][0] << "\n";
	//kill();
	return 0;
}