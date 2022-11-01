#define _CRT_SECURE_NO_WARNINGS

#pragma GCC optimize("O3")

#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cstring>
#include <numeric>
#include <set>
#include <queue>
#include <deque>
#include <array>
#include <string>
#include <cmath>
#include <random>
#include <ctime>
#include <map>
#include <functional>
#include <bitset>
#include <complex>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using ld = long double;

const int inf = 1e9;

int gcd(int a, int b) {
	return (b ? gcd(b, a % b) : a);
}

bool isec(pii a, pii b) {
	return !(a.second < b.first || b.second < a.first);
}

void ok() {
	//assert(false);
	cout << "NO";
	exit(0);
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vi SA(n), EA(n), SB(n), EB(n);
	vector<pii> seg(n);
	for (int i = 0; i < n; i++) {
		int sa, ea, sb, eb;
		cin >> sa >> ea >> sb >> eb;
		SA[i] = sa;
		EA[i] = ea;
		SB[i] = sb;
		EB[i] = eb;
		seg[i] = { SB[i], EB[i] };
	}

	auto solve = [&]() {

		vi idl(n), idr(n);
		iota(all(idl), 0);
		iota(all(idr), 0);
		sort(all(idl), [&](int i, int j) { return SA[i] < SA[j]; });
		sort(all(idr), [&](int i, int j) { return EA[i] < EA[j]; });

		{
			auto cmpl = [&](int i, int j) { return SB[i] < SB[j]; };
			auto cmpr = [&](int i, int j) { return EB[i] < EB[j]; };
			multiset<int, decltype(cmpl) > setikl(cmpl);
			multiset<int, decltype(cmpr) > setikr(cmpr);
			int pt = -1;
			for (int i = 0; i < n; i++) {
				int cur = idl[i];
				while (pt + 1 < n && EA[idr[pt + 1]] < SA[cur]) {
					pt++;
					int id = idr[pt];
					setikl.insert(id);
					setikr.insert(id);
				}
				{
					auto it = setikl.insert(cur);
					auto nxt = next(it);
					if (nxt != setikl.end()) {
						if (isec(seg[cur], seg[*nxt])) ok();
					}
					if (it != setikl.begin()) {
						it--;
						if (isec(seg[cur], seg[*it])) ok();
						it++;
					}
					setikl.erase(it);
				}
				{
					auto it = setikr.insert(cur);
					auto nxt = next(it);
					if (nxt != setikr.end()) {
						if (isec(seg[cur], seg[*nxt])) ok();
					}
					if (it != setikr.begin()) {
						it--;
						if (isec(seg[cur], seg[*it])) ok();
						it++;
					}
					setikr.erase(it);
				}
			}
		}
		{
			auto cmpl = [&](int i, int j) { return SB[i] < SB[j]; };
			auto cmpr = [&](int i, int j) { return EB[i] < EB[j]; };
			multiset<int, decltype(cmpl) > setikl(cmpl);
			multiset<int, decltype(cmpr) > setikr(cmpr);
			int pt = n;
			for (int i = n - 1; i >= 0; i--) {
				int cur = idr[i];
				while (pt > 0 && SA[idl[pt - 1]] > EA[cur]) {
					pt--;
					int id = idl[pt];
					setikl.insert(id);
					setikr.insert(id);
				}
				{
					auto it = setikl.insert(cur);
					auto nxt = next(it);
					if (nxt != setikl.end()) {
						if (isec(seg[cur], seg[*nxt])) ok();
					}
					if (it != setikl.begin()) {
						it--;
						if (isec(seg[cur], seg[*it])) ok();
						it++;
					}
					setikl.erase(it);
				}
				{
					auto it = setikr.insert(cur);
					auto nxt = next(it);
					if (nxt != setikr.end()) {
						if (isec(seg[cur], seg[*nxt])) ok();
					}
					if (it != setikr.begin()) {
						it--;
						if (isec(seg[cur], seg[*it])) ok();
						it++;
					}
					setikr.erase(it);
				}
			}
		}
	};

	solve();
	for (int i = 0; i < n; i++) {
		swap(SA[i], SB[i]);
		swap(EA[i], EB[i]);
		seg[i] = { SB[i], EB[i] };
	}
	solve();
	cout << "YES";
}