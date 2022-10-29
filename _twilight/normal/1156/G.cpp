#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

typedef class Operation {
	public:
		char op;
		int x, y;

		Operation() : op('='), x(-1), y(-1) {	}
		Operation(char op, int x, int y) : op(op), x(x), y(y) {	}

		boolean operator < (Operation b) const {
			if (op != b.op) return op < b.op;
			if (x != b.x) return x < b.x;
			return y < b.y;
		}
} Operation;

int n, m;

boolean is_op[256];
map<string, int> val;
map<int, string> org;
vector<string> result;
map<int, Operation> G;
map<Operation, int> rG;
map<int, string> new_var;

void add(string x) {
	org[m] = x;
	val[x] = m++;
}

string make_new() {
	string s = "aaaa";
	do {
		s[rand() % 4] = rand() % 26 + 'a';
	} while (val.count(s));
	val[s] = -1;
	return s;
}

void dfs(int v, boolean top = false) {
	if (org.count(v)) {
		if (top && org[v] != "res") {
			result.push_back("res=" + org[v]);
		}
		new_var[v] = org[v];
		return;
	}
	if (new_var.count(v)) {
		return;
	}
	Operation op = G[v];
	dfs(op.x);
	dfs(op.y);
	result.push_back((new_var[v] = (top ? ("res") : (make_new()))) + "=" + new_var[op.x] + op.op + new_var[op.y]);
}

int main() {
#ifdef local
	freopen("input.txt", "r", stdin);
#endif
	srand(233);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	is_op['$'] = true;
	is_op['^'] = true;
	is_op['#'] = true;
	is_op['&'] = true;

	string str, a, b, c;
	cin >> n;
	while (n--) {
		cin >> str;
		int idx = str.find('='), idx1;
		a = str.substr(0, idx);
		for (idx1 = idx; idx < (signed) str.size() && !is_op[str[idx]]; idx++);
		if (idx == (signed) str.size()) {
			b = str.substr(idx1 + 1);
			if (!val.count(b)) {
				add(b);
			}
			val[a] = val[b];
		} else {
			b = str.substr(idx1 + 1, idx - idx1 - 1);
			c = str.substr(idx + 1);
			if (!val.count(b)) {
				add(b);
			}
			if (!val.count(c)) {
				add(c);
			}
			Operation op (str[idx], val[b], val[c]);
			if (!rG.count(op)) {
				rG[op] = m;
				G[m] = op;
				val[a] = m++;
			} else {
				val[a] = rG[op];
			}
		}
	}

	if (!val.count("res")) {
		puts("0");
		return 0;
	}

	dfs(val["res"], true);
	cout << result.size() << '\n';
	for (auto& s : result) {
		cout << s << '\n';
	}
	return 0;
}