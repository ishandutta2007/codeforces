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

int a[20];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		sum += a[i];
	}
	for (int mask = 0; mask < (1 << n); mask++){
		int tmp = 0;
		for (int i = 0; i < n; i++){
			if (mask & (1 << i))
				tmp += a[i];
		}
		int t = sum - tmp;
		tmp %= 360;
		t %= 360;
		if (tmp == t)
			return cout << "YES" << endl, 0;
	}
	cout << "NO" << endl;
}