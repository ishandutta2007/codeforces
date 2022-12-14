#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;

int a[maxn], p[maxn], s[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		p[i] = (p[i - 1] | a[i]);
	for (int i = n; i >= 1; i--)
		s[i] = (s[i + 1] | a[i]);
	int mx = -1, idx = -1;
	for (int i = 1; i <= n; i++){
		int t = (p[i - 1] | s[i + 1]);
		t = (t & a[i]);
		t = (a[i] - t);
		if (mx == -1 or mx < t){
			mx = t;
			idx = i;
		}
	}
	cout << a[idx] << " ";
	for (int i = 1; i <= n; i++)
		if (i != idx)
			cout << a[i] << " ";
	cout << endl;
}