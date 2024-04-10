#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define mp make_pair
#define pll pair<long long, long long>
#define all(s) (s).begin(), (s).end()

int main(){
	#ifdef LOCAL
	freopen("a.in", "r",stdin);
	freopen("a.out", "w", stdout);
	#endif
	int n, x, h;
	cin >> n >> h;
	int cnt = n;
	for(int i = 0; i < n; i++){
		cin >> x;
		cnt += (x > h);
	}
	cout << cnt << endl;

	return 0;
}