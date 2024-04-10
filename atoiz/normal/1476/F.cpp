#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <deque>

using namespace std;

struct State { 
	int minEmpty, maxFilled;
	int prvID, pos, dir;
	State(int _minEmpty = 0, int _maxFilled = -1): 
		minEmpty(_minEmpty), maxFilled(_maxFilled), prvID(-1), pos(-1), dir(0) {}
};

bool operator>= (State lhs, State rhs) {
	return (lhs.minEmpty >= rhs.minEmpty) and (lhs.maxFilled >= rhs.maxFilled);
}

int main() {
	// freopen("in.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int numTests;
	cin >> numTests;

	vector<State> statesPool;
	vector<int> statesStack;
	statesPool.reserve(3e5);
	statesStack.reserve(3e5);

	while (numTests--) {
		int N;
		cin >> N;

		statesPool.clear();
		statesStack.clear();
		statesPool.emplace_back(0, -1);
		statesStack.push_back(0);

		for (int pos = 0; pos < N; ++pos) {
			int power, lef, rig;
			State addLef, addRig;

			cin >> power;
			if (power == 0) continue;

			auto addRange = [&](int id, int dir) {
				auto state = statesPool[id];
				if (lef <= state.minEmpty) {
					state.minEmpty = max(state.minEmpty, rig + 1);
				}

				if (state.minEmpty >= pos and state.maxFilled >= pos) {
					state.minEmpty = max(state.minEmpty, state.maxFilled + 1);
				}

				state.maxFilled = max(state.maxFilled, max(pos, rig));
				state.prvID = id, state.pos = pos, state.dir = dir;
				return state;
			};

			vector<State> toAdd;

			if (pos > 0) {
				lef = max(0, pos - power), rig = pos - 1;
				auto curState = addRange(statesStack.back(), 0);
				for (auto it = next(statesStack.rbegin()); it != statesStack.rend(); ++it) {
					auto candidate = addRange(*it, 0);
					if (candidate >= curState) {
						curState = candidate;
					} else {
						break;
					}
				}
				toAdd.push_back(curState);
			}

			if (pos < N - 1) {
				lef = pos + 1, rig = min(N - 1, pos + power);
				auto curState = addRange(statesStack.back(), 1);
				for (auto it = next(statesStack.rbegin()); it != statesStack.rend(); ++it) {
					auto candidate = addRange(*it, 1);
					if (candidate >= curState) {
						curState = candidate;
					} else {
						break;
					}
				}
				toAdd.push_back(curState);
			}

			sort(toAdd.begin(), toAdd.end(), [](const State &lhs, const State &rhs) {
				return make_pair(lhs.minEmpty, lhs.maxFilled) < make_pair(rhs.minEmpty, rhs.maxFilled);
			});

			if ((int) toAdd.size() == 2 and toAdd[1] >= toAdd[0]) {
				toAdd.erase(toAdd.begin());
			}

			for (auto curState : toAdd) {				
				while (!statesStack.empty() and curState >= statesPool[statesStack.back()]) {
					statesStack.pop_back();
				}
				statesStack.push_back((int) statesPool.size());
				statesPool.push_back(curState);
			}
		}

		bool possible = false;
		for (auto startID : statesStack) {
			if (statesPool[startID].minEmpty == N) {
				possible = true;
				string ans(N, 'L');

				for (int id = startID; id > 0; id = statesPool[id].prvID) {
					if (statesPool[id].dir) {
						ans[statesPool[id].pos] = 'R';
					}
				}

				cout << "YES\n" << ans << '\n';
				break;
			}
		}

		if (not possible) {
			cout << "NO\n";
		}
	}
}