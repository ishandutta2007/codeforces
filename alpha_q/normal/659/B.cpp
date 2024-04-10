#include <bits/stdc++.h>

using namespace std;

typedef pair <int, string> pis;

const int MAX = 1e4 + 10;

int n, m, a, b; string s;
priority_queue <pis> PQ[MAX];

int main() {	
	//freopen("input.txt", "r", stdin);
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n >> m; while (n--) {
		cin >> s >> a >> b;
		PQ[a].push(make_pair(b, s));
	}

	for (int i = 1; i <= m; i++) {
		pis p, q, r = make_pair(-1, "-1");
		p = PQ[i].top(); PQ[i].pop();
		q = PQ[i].top(); PQ[i].pop();
		if (!PQ[i].empty()) {
			r = PQ[i].top(); 
			PQ[i].pop();
		}

		if (r.first == q.first) {
			cout << "?\n";
			continue;
		}
		
		cout << p.second << " " << q.second << endl;
	}

	cout.flush();
    return 0;
}