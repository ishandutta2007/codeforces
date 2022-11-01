#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


const int N = 1000 * 1000 * 1000 + 7;
vector<int> in;
vector<int> out;
int a[205];
int main() {
	int n, k, ans = -N;
	cin >> n;
	cin >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int l = 0; l < n; l++) {
		for (int r = l; r < n; r++) {
			in.clear();
			out.clear();
			int s = 0;
			for (int i = 0; i < l; i++)
				out.push_back(a[i]);
			for (int i = l; i <= r; i++) {
				in.push_back(a[i]);
				s += a[i];
			}
			for (int i = r + 1; i < n; i++) 
				out.push_back(a[i]);
			sort(in.begin(), in.end());
			sort(out.begin(), out.end());
			for (int i = 0; i < out.size() && i < in.size() && i < k && in[i] < out[out.size() - 1 - i]; i++) {
				s = s - in[i] + out[out.size() - 1 - i];
			}
			ans = max(ans, s);
		}
	}
	cout << ans;
	return 0;
}