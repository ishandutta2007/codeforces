#include <cstdio>
#include <iostream>
#include <cassert>
#include <random>
#include <set>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

mt19937 gen(1);

map<int, vector<int>> memo;

vector<int> ask(int x) {
    if (memo.count(x)) {
        return memo[x];
    }
    cout << "? " << x << endl;
    int cnt;
    cin >> cnt;
    vector<int> edges(cnt);
    for (auto& el : edges) {
        cin >> el;
    }
    return memo[x] = edges;
}

int check(map<int, int>& height, int k) {
    for (auto& [v, h] : height) {
        if (h == k) {
            return v;
        }
        else if (h + 1 == k) {
            auto edges = ask(v);
            for (auto u : edges) {
                auto edges_u = ask(u);
                if (edges_u.size() == 2u) {
                    return u;
                }
            }
        }
        else if (h + 2 == k) {
            auto edges_v = ask(v);
            set<int> cands;
            for (auto u : edges_v) {
                auto edges_u = ask(u);
                for (auto w : edges_u) {
                    if (memo.count(w)) {
                        if (memo[w].size() == 2) {
                            return w;
                        } 
                    }
                    else if (w != v) {
                        cands.insert(w);
                    }
                }
            }
            assert(cands.size() > 0);
            while (cands.size() > 1) {
                auto cand = *cands.begin();
                cands.erase(cands.begin());
                auto resp = ask(cand);
                if (resp.size() == 2) {
                    return cand;
                }
            }
            //assert(cands.size() > 0);
            //auto resp = ask(*cands.begin());
            //assert(resp.size() == 2);
            return *cands.begin();
        }
    }
    return 0;
}

void solve() {
    memo.clear();
    int k;
    cin >> k;
    if (!k) return;
    int first = gen() % ((1 << k) - 1) + 1;
    auto resp = ask(first);
    vector<int> chain = { first };


    set<int> used;
    used.insert(first);
    while (true) {
        int v = -1;
        for (auto u : resp) {
            if (!used.count(u)) {
                v = u;
                used.insert(v);
                break;
            }
        }

        chain.push_back(v);
        resp = ask(v);
        if (resp.size() == 2u) {
            cout << "! " << v << endl;
            return;
        }
        if (resp.size() == 1) {
            break;
        }
    }
    if (memo[first].size() > 1) {
        reverse(chain.begin(), chain.end());
        resp = memo[first];
        while (true) {
            int v = -1;
            for (auto u: resp) {
                if (!used.count(u)) {
                    v = u;
                    used.insert(v);
                    break;
                }
            }

            chain.push_back(v);
            resp = ask(v);
            if (resp.size() == 2u) {
                cout << "! " << v << endl;
                return;
            }
            if (resp.size() == 1) {
                break;
            }
        }
    }

    map<int, int> height;
    for (size_t i = 0; i < chain.size(); ++i) {
        int cur_h = (int)i + 1;
        if (i > chain.size() / 2) {
            cur_h = (int)(chain.size() - i);
        }
        height[chain[i]] = cur_h;
    }
    assert(chain.size() % 2);
    for (auto u : memo[chain[chain.size() / 2]]) {
        if (!height.count(u)) {
            height[u] = height[chain[chain.size() / 2]] + 1;
        }
    }

    while (true) {
        int answer = check(height, k);
        if (answer) {
            cout << "! " << answer << endl;
            return;
        }

        int max_h = -1;
        int v = -1;
        for (auto& [u, h] : height) {
            if (h > max_h) {
                max_h = h;
                v = u;
            }
        }

        int cur_v = v;
        vector<int> path = { cur_v };
        for (int i = 0; i < max_h - 1; ++i) {
            auto resp = ask(cur_v);
            if (resp.size() == 2) {
                cout << "! " << cur_v << endl;
                return;
            }
            for (auto u : resp) {
                if (!height.count(u) && (path.size() < 2 || u != path[(int)path.size() - 2])) {
                    cur_v = u;
                    path.push_back(cur_v);
                    break;
                }
            }
        }
        auto resp = ask(cur_v);
		if (resp.size() == 2) {
			cout << "! " << cur_v << endl;
			return;
		} else if (resp.size() == 1u) {
            reverse(path.begin(), path.end());
            for (size_t i = 0; i < path.size(); ++i) {
                height[path[i]] = i + 1;
            }
            reverse(path.begin(), path.end());
            for (auto u : ask(v)) {
                if (!height.count(u) && u != path[1]) {
                    height[u] = height[v] + 1;
                    break;
                }
            }
        }
        else {
            height[path[1]] = height[v] + 1;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}