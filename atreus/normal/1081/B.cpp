#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, ll> pii;
const int maxn = 1e5 + 10;

int a[maxn], mark[maxn], last[maxn], cnt[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		mark[a[i]] ++;
	}
	for (int i = 0; i < n; i++){
		if (mark[i] % (n - i) != 0){
			return cout << "Impossible" << endl, 0;
		}
	}
	cout << "Possible" << endl;
	int newint = 1;
	for (int i = 1; i <= n; i++){
		if (cnt[a[i]] == 0){
			cnt[a[i]] = n - a[i];
			last[a[i]] = newint ++;
		}
		cout << last[a[i]] << " ";
		cnt[a[i]] --;
	}
	cout << endl;
}