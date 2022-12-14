#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = 2e5 + 10;

ll s[maxn], p[maxn];

int main() {
	ios_base::sync_with_stdio (false);
	int n, d;
	cin >> n >> d;
	for (int i = 1; i <= n; i++)
		cin >> s[i];
	
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}
	s[d] += p[1];
	int ptr = 2;
	int rank = d;
	for (int i = d - 1; i >= 1; i--) {
		while (ptr <= n and p[ptr] + s[i] > s[d])
			ptr ++;
		rank -= (ptr <= n);
		ptr ++;
	}
	cout << rank << endl;
}