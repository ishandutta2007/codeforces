#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

int N;
string S;

int ask(string str)
{
	cout << "? " << str << endl;
	int k;
	cin >> k;
	assert(k >= 0);
	for (int _ = 0; _ < k; ++_) {
		int i;
		cin >> i;
		--i;
		for (int j = 0; j < (int) str.size(); ++j) {
			assert(S[i + j] == '?' || S[i + j] == str[j]);
			S[i + j] = str[j];
		}
	}	

	return k;
}

void answer()
{
	assert(!count(S.begin(), S.end(), '?'));
	cout << "! " << S << endl;
	int verdict;
	cin >> verdict;
	assert(verdict == 1);
}

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int tests;
	cin >> tests;
	while (tests--) {
		cin >> N;
		S = string(N, '?');

		if (N > 4) {
			ask("CC");
			ask("CH");
			ask("CO");
			ask("HO");
			ask("OH");

			if (count(S.begin(), S.end(), '?') == N) {
				if (!ask(string(N - 1, 'O'))) {
					for (int i = 0; i < N - 1; ++i) {
						S[i] = 'H';
					}
				}

				if (ask(S.substr(0, N - 1) + 'C')) {
					S[N - 1] = 'C';
				} else {
					S[N - 1] = S[N - 2];
				}

				answer();
			} else {
				int last = N - 1;
				while (S[last] == '?') --last;
				assert(last == N - 1 || S[last] != 'C');
				for (; last < N - 2; ++last) {
					S[last + 1] = S[last];
				}

				int first = 0;
				while (S[first] == '?') ++first;
				if (S[first] != 'C') {
					for (; first > 0; --first) {
						S[first - 1] = S[first];
					}
				}

				for (int i = first; i < last; ++i) {
					if (S[i + 1] == '?') {
						assert(S[i] != 'C');
						S[i + 1] = S[i];
					}
				}

				if (first > 0) {
					assert(S[first] == 'C');
					if (ask(string(first, 'O') + S.substr(first, last - first + 1))) {
						for (int i = 0; i < first; ++i) {
							S[i] = 'O';
						}
					} else {
						for (int i = 0; i < first; ++i) {
							S[i] = 'H';
						}
					}
				}

				if (last < N - 1) {
					if (ask(S.substr(0, N - 1) + 'C')) {
						S[N - 1] = 'C';
					} else {
						S[N - 1] = S[N - 2];
					}
				}
				answer();
			}
		} else {
			assert(N == 4);

			if (count(S.begin(), S.end(), '?') == N) {
				ask("HO");
				ask("OH");
				ask("CO");
				ask("CH");
			}

			if (count(S.begin(), S.end(), '?') != 0 && count(S.begin(), S.end(), '?') != N) {
				int start = 0;
				while (S[start] == '?') ++start;
				for (int i = start + 1; i < N; ++i) {
					if (S[i] != '?') continue;

					ask(S.substr(start, i - start) + "O");
					if (S[i] != '?') continue;

					ask(S.substr(start, i - start) + "H");
					if (S[i] != '?') continue;

					S[i] = 'C';
				}

				assert(S[N - 1] != '?');
				for (int i = N - 2; i >= 0; --i) {
					if (S[i] != '?') continue;

					ask("O" + S.substr(i + 1));
					if (S[i] != '?') continue;

					ask("H" + S.substr(i + 1));
					if (S[i] != '?') continue;

					S[i] = 'C';
				}
			}

			if (count(S.begin(), S.end(), '?') == N) {
				ask("HHH");
				ask("CCC");
				ask("OOO");
			}

			if (count(S.begin(), S.end(), '?') != 0 && count(S.begin(), S.end(), '?') != N) {
				assert(S[1] != '?' && S[2] != '?');
				assert(S[0] != '?' || S[3] != '?');
				if (S[0] == '?') {
					if (ask("O" + S.substr(1))) {
						S[0] = 'O';
					} else {
						S[0] = 'H';
					}
				} else {
					if (ask(S.substr(0, N - 1) + "C")) {
						S[N - 1] = 'C';
					} else {
						S[N - 1] = S[N - 2];
					}
				}
			}

			if (count(S.begin(), S.end(), '?') == N) {
				if (ask("OOCC")) {
					S = "OOCC";
				} else {
					S = "HHCC";
				}
			}

			answer();
		}
	}

	return 0;
}