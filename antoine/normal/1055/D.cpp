#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void no() {
	cout << "NO\n";
	exit(0);
}

struct Change {
	string s1, s2;
	int l = 0, r = 0;

	Change() {
	}

	Change(string _s1, string _s2) :
			s1(_s1), s2(_s2) {
		l = 0, r = (int) s1.size() - 1;
		while (s1[l] == s2[l])
			++l;
		while (s1[r] == s2[r])
			--r;
	}

	void remL(const int x) {
		l -= x;
		r -= x;
		s1 = s1.substr(x);
		s2 = s2.substr(x);
	}

	void remR(const int x) {
		s1.resize(s1.size() - x);
		s2.resize(s2.size() - x);
	}

	int size() {
		return (int) s1.size();
	}

	pair<char, char> operator[](const int i) {
		return {s1[i], s2[i]};
	}

	void print() {
		//cerr << s1 << ' ' << s2 << ' ' << l << ' ' << r << endl;
	}
};

Change merge(Change ch1, Change ch2) {
	//cerr << "merging\n";

	ch1.print();
	ch2.print();
	//cerr << endl;

	if (ch1.r - ch1.l != ch2.r - ch2.l)
		no();

	if (ch1.l > ch2.l)
		swap(ch1, ch2);

	ch2.remL(ch2.l - ch1.l);

	ch1.remR(ch1.size() - ch2.size());
	ch2.remR(ch2.size() - ch1.size());


	ch1.print();
	ch2.print();
	//cerr << endl;

	assert(ch1.l == ch2.l && ch1.r == ch2.r);
	assert(ch1.size() == ch2.size());

	int l = ch1.l, r = ch1.r;
	for (int i = l; i <= r; ++i)
		if (ch1[i] != ch2[i])
			no();

	while (l && ch1[l - 1] == ch2[l - 1])
		--l;
	while (r + 1 < ch1.size() && ch1[r + 1] == ch2[r + 1])
		++r;


	ch1.print();
	ch2.print();
	//cerr << endl;

	Change res;
	res.s1 = ch1.s1.substr(l, r + 1 - l);
	res.s2 = ch1.s2.substr(l, r + 1 - l);
	res.l = ch1.l - l;
	res.r = ch1.r - l;
	res.print();
	return res;
}

const int MaxN = 3009;

namespace RK { // Rabin Karp

const int mod[2] = { (int) 1e9 + 7, (int) 1e9 + 9 };
const int prime[2] = { 179, 233 };
ll pPow[MaxN + 9][2];
ll h[MaxN + 9][2];

void init(const string &s) {
	if (!pPow[0][0]) {
		pPow[0][0] = pPow[0][1] = 1;
		for (int i = 1; i <= MaxN; ++i)
			for (int z = 0; z < 2; ++z)
				pPow[i][z] = pPow[i - 1][z] * prime[z] % mod[z];
	}
	for (int i = 0; i < (int) s.size(); ++i)
		for (int z = 0; z < 2; ++z)
			h[i + 1][z] = (h[i][z] * prime[z] + s[i]) % mod[z];
}

array<ll, 2> query(const int l, const int r) {
	array<ll, 2> res;
	for (int z = 0; z < 2; ++z) {
		res[z] = (h[r + 1][z] - h[l][z] * pPow[r - l + 1][z]) % mod[z];
		if (res[z] < 0)
			res[z] += mod[z];
	}
	return res;
}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	vector<string> a(n), b(n);
	for (string &x : a)
		cin >> x;
	for (string &x : b)
		cin >> x;

	Change ch;

	for (int i = 0; i < n; ++i)
		if (a[i] != b[i]) {
			if (ch.size() == 0)
				ch = Change(a[i], b[i]);
			else
				ch = merge(ch, Change(a[i], b[i]));
			assert(ch.size() != 0);
		}

	assert(ch.size() != 0);

	RK::init(ch.s1);
	const int k = (int) ch.size();
	const array<ll, 2> h = RK::query(0, k - 1);

	auto it = b.begin();
	for (string &s : a) {
		RK::init(s);
		for (int i = 0; i + k <= (int) s.size(); ++i)
			if (RK::query(i, i + k - 1) == h) {
				s = s.substr(0, i) + ch.s2 + s.substr(i + (int) ch.s2.size());
				break;
			}
		if (s != *it)
			no();
		it++;
	}
	cout << "YES\n";
	cout << ch.s1 << '\n';
	cout << ch.s2 << '\n';

	return 0;
}