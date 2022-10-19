/*input
0 1 2 3
3 5 6 8

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <array>

using namespace std;

using State = array<int64_t, 4>;
using Moves = vector<pair<int64_t, int64_t>>;

int64_t get_jump(int64_t x, int64_t y)
{
	return 2 * y - x;
}

void reverse_moves(Moves &moves)
{
	reverse(moves.begin(), moves.end());
	for (auto &p : moves) {
		p.first = get_jump(p.first, p.second);
	}
}

Moves withdraw_flipped(State arr)
{
	const static int64_t SMALL_LIMIT = 8;
	assert(arr[0] == 0);
	sort(arr.begin(), arr.end());
	assert(arr[0] == 0);

	Moves sol;

	auto jump = [&](int64_t &x, int64_t &y) {
		sol.emplace_back(x, y);
		x = 2 * y - x;

		if (x < 0) {
			sol.emplace_back(x, 0);
			x = -x;
		}
	};

	while (true) {
		sort(arr.begin(), arr.end());
		// cout << sol.size() << ": ";
		// for (auto &x : arr) {
		// 	cout << x << ' ';
		// }
		// cout << endl;

		assert(arr[3] != 0);
		if (arr[3] == 1) {
			break;
		} else if (arr[3] <= SMALL_LIMIT) {
			if (arr[3] != arr[2]) {
				jump(arr[3], arr[2]);
			} else {
				jump(arr[3], arr[1]);
			}
		} else if (abs(get_jump(arr[3], arr[2])) <= arr[3] / 2) {
			jump(arr[3], arr[2]);
		} else if (abs(get_jump(arr[3], arr[1])) <= arr[3] / 2) {
			jump(arr[3], arr[1]);
		} else if (get_jump(arr[3], arr[1]) >= arr[3] / 2) {
			jump(arr[3], arr[1]);
		} else if (get_jump(arr[3], arr[2]) <= -arr[3] / 2) {
			sol.emplace_back(arr[1], 0);
			sol.emplace_back(-arr[1], arr[2]);
			arr[1] += 2 * arr[2];
		} else {
			if (arr[1] - arr[0] < arr[3] - arr[2]) {
				sol.emplace_back(arr[1], arr[2]);
				sol.emplace_back(get_jump(arr[1], arr[2]), arr[3]);
				arr[1] += 2 * (arr[3] - arr[2]);
			} else {
				sol.emplace_back(arr[2], arr[1]);
				sol.emplace_back(get_jump(arr[2], arr[1]), 0);
				arr[2] -= 2 * arr[1];
			}
		}
	}

	return sol;
}

Moves withdraw(State arr)
{
	auto o = arr[0];
	for (auto &x : arr) x -= o;

	Moves sol;

	for (int i = 0; i < 4; ++i) {
		if (arr[i] < 0) {
			sol.emplace_back(arr[i], 0);
			arr[i] = -arr[i];
		}
	}

	auto main_sol = withdraw_flipped(arr);
	sol.insert(sol.end(), main_sol.begin(), main_sol.end());

	for (auto &p : sol) {
		p.first += o;
		p.second += o;
	}

	return sol;
}
	
Moves solve_compressed(State from, State to)
{
	assert(is_sorted(from.begin(), from.end()));
	assert(is_sorted(to.begin(), to.end()));
	assert(from[0] == 0);

	// for (auto &x : from) cout << x << ' '; cout << endl;

	auto step1 = withdraw(from);

	auto arr = from;
	for (auto &x : arr) {
		x &= 1;
	}
	sort(arr.begin(), arr.end());
	swap(arr[2], arr[3]);

	for (auto &x : to) {
		if (!((x ^ arr.back()) & 1)) {
			swap(x, to[0]);
			break;
		}
	}
	auto o = to[0];
	assert(!((o ^ arr.back()) & 1));
	arr.back() = o;
	
	auto step2 = withdraw(arr);
	reverse_moves(step2);

	swap(arr.front(), arr.back());
	assert(arr.front() == o);

	auto step3 = withdraw(arr);

	auto step4 = withdraw(to);
	reverse_moves(step4);

	Moves sol;
	sol.insert(sol.end(), step1.begin(), step1.end());
	sol.insert(sol.end(), step2.begin(), step2.end());
	sol.insert(sol.end(), step3.begin(), step3.end());
	sol.insert(sol.end(), step4.begin(), step4.end());
	return sol;
}

Moves solve(State from, State to)
{
	assert(is_sorted(from.begin(), from.end()));
	assert(is_sorted(to.begin(), to.end()));

	auto o = from[0];
	auto g = __gcd(__gcd(from[1] - from[0], from[2] - from[1]), from[3] - from[2]);

	for (auto &x : from) {
		assert(abs(x - o) % g == 0);
		x = (x - o) / g;
	}

	for (auto &x : to) {
		assert(abs(x - o) % g == 0);
		x = (x - o) / g;
	}

	auto sol = solve_compressed(from, to);
	for (auto &p : sol) {
		p.first = p.first * g + o;
		p.second = p.second * g + o;
	}

	return sol;
}

bool check_plausible(State from, State to)
{
	// sort(from.begin(), from.end()); // redundant
	auto g = __gcd(__gcd(from[1] - from[0], from[2] - from[1]), from[3] - from[2]); // guaranteed g != 0
	auto h = __gcd(__gcd(to[1] - to[0], to[2] - to[1]), to[3] - to[2]);

	if (g != h) {
		return false;
	}

	for (auto x : to) {
		if (abs(x - from[0]) % g != 0) {
			return false;
		}
	}

	array<int, 2> cnt = {0, 0};
	
	for (auto x : from) {
		++cnt[(abs(x - from[0]) / g) & 1];
	}

	for (auto x : to) {
		--cnt[(abs(x - from[0]) / g) & 1];
	}

	if (cnt[0] != 0 || cnt[1] != 0) return false;
	return true;
}

Moves trim(Moves moves)
{
	Moves sol;
	for (auto &p : moves) {
		if (p.first == p.second) continue;
		if (sol.empty() || sol.back() != make_pair(get_jump(p.first, p.second), p.second)) {
			sol.push_back(p);
		} else {
			sol.pop_back();
		}
	}
	return sol;
}

int main()
{
	// const int END = 1e9;
	// auto moves = withdraw({-END, -END / 2 + 1, END / 2 + 1, END});
	// cout << moves.size() << endl;
	// return 0;

	State from, to;
	for (auto &x : from) cin >> x;
	for (auto &x : to) cin >> x;

	sort(from.begin(), from.end());
	sort(to.begin(), to.end());

	if (from.front() == from.back()) { // if all equal -> special case
		if (to.front() == from.front() && to.back() == from.front()) {
			cout << 0 << endl;
		} else {
			cout << -1 << endl;
		}
		return 0;
	}

	if (!check_plausible(from, to)) {
		cout << -1 << endl;
	} else {
		auto sol = trim(solve(from, to));
		cout << sol.size() << '\n';
		for (auto p : sol) {
			cout << p.first << ' ' << p.second << '\n';
		}
	}
}