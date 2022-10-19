/*input
2
0123
3210

*/

#include <iostream>

using namespace std;

const int MAXN = 21;
int N;
uint64_t A[1 << MAXN], B[1 << MAXN], and_mask, add_mask;
string strA, strB;

uint64_t add(uint64_t x, uint64_t y)
{ return (x + y) & and_mask; }

uint64_t sub(uint64_t x, uint64_t y)
{ return (add_mask + x - y) & and_mask; }

void sum_of_subset(uint64_t *arr, bool inv)
{
	for (int j = 0; j < N; ++j) {
		for (int i = (1 << N) - 1; i >= 0; --i) {
			if ((i >> j) & 1) {
				if (inv) {
					arr[i] = sub(arr[i], arr[i ^ (1 << j)]);
				} else {
					arr[i] = add(arr[i], arr[i ^ (1 << j)]);
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> strA >> strB;
	for (int i = 0; i < N; ++i) {
		and_mask |= 3ull << (3 * i);
		add_mask |= 4ull << (3 * i);
	}

	for (int i = 0; i < (1 << N) - 1; ++i) {
		int len = __builtin_popcount(i);
		A[i] = uint64_t(strA[i] & 3) << (3 * len);
		B[i] = uint64_t(strB[i] & 3) << (3 * len);
	}

	sum_of_subset(A, 0);
	sum_of_subset(B, 0);

	for (int i = 0; i < (1 << N) - 1; ++i) {
		uint64_t cur = 0;
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < (int) ((B[i] >> (3 * j)) & 3); ++k) {
				cur = add(cur, A[i] << (3 * j));	
			}
		}
		A[i] = cur;
	}

	sum_of_subset(A, 1);

	string ans(1 << N, 0);
	for (int i = 0; i < (1 << N) - 1; ++i) {
		int len = __builtin_popcount(i);
		ans[i] = 48 + ((A[i] >> (3 * len)) & 3);
	}
	int last = 0;
	for (int i = 0; i < (1 << N); ++i) {
		last += strA[i] * strB[((1 << N) - 1) ^ i];
	}
	ans.back() = 48 + (last & 3);
	cout << ans << endl;
}