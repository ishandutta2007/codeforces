#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
        cin >> a[i];
    if(n < k) {
        cout << -1 << '\n';
        return 0;
	}
    sort(a.begin(), a.end());
    int x = a[n - k];
    cout << x << ' ' << x << '\n';
}