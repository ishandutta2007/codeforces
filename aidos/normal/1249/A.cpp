#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
int n;
int a[1111];

int main () {
	int q;
	cin>> q;
	for(int i=0; i < q; i++){
		cin >> n;
		for(int j = 0; j < n; j++) {
			cin >> a[j];
		}
		sort(a, a + n);
		int t = 0;
		while(t + 1 < n && a[t + 1] - a[t] > 1) t++;
		if(t + 1 == n) cout << 1 << "\n";
		else cout << 2 << "\n";
	}
 	return 0;
}