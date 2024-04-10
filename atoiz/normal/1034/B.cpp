/*input
3 3
*/

#include <iostream>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	if (N > M) swap(N, M);

	if (N == 1) cout << M / 6 * 6 + max(M % 6 - 3, 0) * 2 << endl;
	else if (N == 2) {
		if (M == 2) cout << 0 << endl;
		else if (M == 3) cout << 4 << endl;
		else if (M == 7) cout << 12 << endl;
		else cout << (int64_t) N * M / 2 * 2 << endl;
	} else {
		cout << (int64_t) N * M / 2 * 2 << endl;
	}
	return 0;
}