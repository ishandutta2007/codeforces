#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 1000000007;
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, K;
	cin >> N >> K;
	N++;
	vector<int> A(N);
	
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int t = 0; t < 2; t++) {
		int cur = 0;
		vector<int> bit(N + 40, 0);
		for (int i = 0; i < N + 40; i++) {
			if (i < N) {
				cur += A[i];
			}

			if (abs(cur) % 2 == 1) {
				bit[i] = 1;
				cur -= 1;
			}
			cur /= 2;
			//if(i < N + 3)cerr << i<<" " << cur << endl;
		}
		

		if (cur != 0) {
			//cerr << "A" << endl;
			for (int i = 0; i < N; i++) {
				A[i] = -A[i];
			}
			continue;
		}
		

		int diff = 0;

		bool ok = true;
		for (int i = 0; i < N + 40; i++) {
			if (bit[i] == 1) {
				for (int j = i; j < N + 40; j++) {
					if (bit[j] == 1) {
						if (j - i >= 40) {
							ok = false;
							break;
						}

						diff += ((int)1 << (j - i));
					}
				}

				//cerr << diff << endl;

				for (int cur = i; cur >= 0; cur--) {
					if (cur < N) {
						if (cur == N - 1 && A[cur] == diff) {
							res--;
						}

						if(K + A[cur] >= diff){
							res++;
							//cerr << cur << endl;
						}


					}


					diff *= 2;
					if (diff >= ((int)1 << 40))break;
				}



				break;
			}
		}
		if (!ok) {
			res = 0;
		}

		break;

	}

	cout << res << endl;
}