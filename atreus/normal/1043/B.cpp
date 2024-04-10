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
const int maxn = 3e4 + 10;
const int block = 320;

int a[maxn];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	vector <int> v;
	for (int i = 1; i <= n; i++) {
		bool found = 1;
		for (int j = 1; j <= i; j++) {
			int tmp = a[j] - a[j - 1];
			for (int k = j + i; k <= n; k += i) {
				if (a[k] - a[k - 1] != tmp)
					found = 0;
			}
		}
		if (found)
			v.PB (i);
	}
	cout << v.size() << endl;
	for (auto w : v)
		cout << w << " ";
	cout << endl;
}