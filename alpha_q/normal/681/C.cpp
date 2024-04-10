/*

     |\   |  `|` |``\  ```|` |   |  /```\  |``\
     | \  |   |  |__/     |  |___| |     | |__/
     |  \ |   |  |  \     |  |   | |     | |  \
    _|   \|  _|_ |   \ \__)  |   |  \___/  |   \
      	
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 100;

#define endl '\n'

multiset <int> S;
int n, x; string com;
pair <string, int> A[N];

int main (int argc, char const *argv[]) {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(0);

	cin >> n;
	int pos = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> com;
		if (com[0] == 'i') {
			cin >> x;
			S.insert(x);
			A[++pos] = {com, x};
		}

		else if (com[0] == 'r') {
			if (S.empty()) {
				A[++pos] = {"insert", 1};
			} else {
				S.erase(S.begin());
			}
			A[++pos] = {com, 0};
		}

		else {
			cin >> x;
			while (!S.empty() and *S.begin() < x) {
				S.erase(S.begin());
				A[++pos] = {"removeMin", 0};
			}
			
			if (S.empty() or *S.begin() > x) {
				A[++pos] = {"insert", x};
				S.insert(x);
			}

			A[++pos] = {com, x};
		}
	}

	cout << pos << endl;
	for (int i = 1; i <= pos; ++i) {
		cout << A[i].first;
		if (A[i].first[0] != 'r') cout << " " << A[i].second;
		cout << endl;
	}

	cout.flush();
	return 0;
}