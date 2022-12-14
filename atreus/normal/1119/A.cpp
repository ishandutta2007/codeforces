#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 3e5 + 10;

int c[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, answer = 0;
	cin >> n;
	int fi = -1, se = -1;
	for (int i = 1; i <= n; i++){
		cin >> c[i];
		if (fi == -1)
			fi = i;
		if (se == -1 and c[i] != c[fi])
			se = i;
		if (fi != -1 and c[i] != c[fi])
			answer = max(answer, i - fi);
		if (se != -1 and c[i] != c[se])
			answer = max(answer, i - se);
	}
	cout << answer << endl;
}