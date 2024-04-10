#include <iostream>
#include <vector>

using namespace std;
using vi_it = vector<int>::iterator;

void solve(vi_it start, int sz, int calls)
{
	if (calls == 1) {
		for (int i = 0; i < sz; ++i) *(start + i) = i + 1;
		return;
	}

    int mid = sz >> 1;
	if (calls == 3) {
        for (int i = 0; i < sz; ++i) *(start + i) = i + 1;
        swap(*(start + mid - 1), *(start + mid));
        return;
	}

    if (calls > 2 * (sz - mid)) {
		solve(start, mid, calls - 2 * (sz - mid));
		solve(start + mid, sz - mid, 2 * (sz - mid) - 1);
    } else {
		solve(start, mid, 1);
		solve(start + mid, sz - mid, calls - 2);
    }

    for (int i = mid; i < sz; ++i) *(start + i) += mid;
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k;
    if (!(k & 1) || k > 2*n - 1) return 0 * puts("-1");
    vector<int> a(n);
    solve(a.begin(), n, k);
    for (int i : a) cout << i << ' ';
}