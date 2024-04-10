/**
 *    author:  Atreus
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 1e5 + 10;
int b[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	multiset<int> s;
	for (int i = 1; i < n; i++)
		s.insert(b[i + 1] - b[i] - 1);
	int answer = n;
	for (int i = 1; i <= n - k; i++){
		answer += *s.begin();
		s.erase(s.begin());
	}
	cout << answer << endl;
}