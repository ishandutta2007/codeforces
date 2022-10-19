#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define M 1001000
#define N 23

int n, a[M];
int t[N][M];

void read(void){
	string s;
	cin >> s;
	n = s.length();
	for (int i = 1; i <= n; ++i){
		if (s[i-1] == '(')
			a[i] = 1 + a[i - 1];
		else
			a[i] = -1 + a[i - 1];
	}

}

void make(void){
	for (int i = 0; i <= n; ++i)
		t[0][i] = a[i];
	for (int j = 1, p=1; j < N; ++j, p*=2)
	for (int i = 0; i <= n; ++i)
		t[j][i] = min(t[j - 1][i], t[j - 1][min(n, i + p)]);
}

int mimi(int l, int r){
	for (int j = 0, p = 1;;++j,p*=2)
	if (2 * p >= r - l + 1)
		return min(t[j][l], t[j][r - p + 1]);
}

void kill(void){
	int m;
	cin >> m;
	for (int i = 0, l, r; i < m; ++i){
		cin >> l >> r;
		int s = a[l-1] - mimi(l-1, r);
		int ws = a[r] - a[l - 1] + s;
		cout << r - l + 1 - s - ws<< "\n";
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
	make();
	kill();

	return 0;
}