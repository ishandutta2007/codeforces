#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

struct Segment {
    int originalLeft, originalRight;
    int left, right, step;

    pair<Segment, Segment> split(int where) {
        int onLeft = (where - left) / step;
        int onRight = (right - left) / step - onLeft - 1;
        Segment l{originalLeft, originalLeft + onLeft,
            left, left + onLeft * step, step};
        Segment r{originalRight - onRight, originalRight,
            right - onRight * step, right, step};
        return make_pair(l, r);
    }

    bool isEmpty() const {
        return originalLeft > originalRight;
    }
};

string brute(string s, int n, int k, vector<pair<int, int>> changes) {
    vector<Segment> segs = {Segment{1, k, 1, k, 1}};
    reverse(changes.begin(), changes.end());
    n = 10;
    for (const auto& p: changes) {
        int l, r;
        tie(l, r) = p;
        int l1 = r + 1, r1 = r + (r - l + 1) / 2;
        int l2 = r1 + 1, r2 = r1 + (r - l + 2) / 2;
        for (int i = 0; i < SZ(segs); ++i) {
            bool splitted = false;
            for (int split: {l1 - 1, r1, l2 - 1, r2}) {
                if (segs[i].left <= split && segs[i].right > split) {
                    auto p = segs[i].split(split);
                    segs.insert(segs.begin() + i + 1, p.second);
                    segs[i] = p.first;
                    splitted = true;
                    break;
                } 
            }
            Segment& curr = segs[i];
            if (curr.left > r2) {
                curr.left -= r - l + 1;
                curr.right -= r - l + 1;
            } else if (l1 <= curr.left && curr.right <= r1) {
                int cnt = (curr.right - curr.left) / curr.step;
                curr.left = l + 1 + (curr.left - l1) * 2;
                curr.step *= 2;
                curr.right = curr.left + cnt * curr.step;
            } else if (l2 <= curr.left && curr.right <= r2) {
                int cnt = (curr.right - curr.left) / curr.step;
                curr.left = l + (curr.left - l2) * 2;
                curr.step *= 2;
                curr.right = curr.left + cnt * curr.step;
            }
        }
    }
    string ans(k, '0');
    for (const Segment& seg: segs) {
        int pos = seg.left;
        for (int i = seg.originalLeft; i <= seg.originalRight; ++i) {
            ans[i - 1] = s[pos - 1];
            pos += seg.step;
        }
    }
    return ans;
}

string solve(const string& s,
             int n, int k,
             vector<pair<int, int>> a) {
    const int INF = 0x3f3f3f3f;
    for (int i = 0; i < n; ++i) {
        a[i].second = a[i].second - a[i].first + 1;
        a[i].first = a[i].first + a[i].second - 1;
    }
    int pmin = -1;
    for (int i = n - 1; i >= 0; --i) {
        if (pmin == -1 || a[i].first < a[pmin].first) {
            pmin = i;
        }
    }
    vector<int> index[2], rem(n), rem1(n);
    index[0] = index[1] = vector<int>(n);
    vector<string> buckets(n + 1);
    for (int i = 0; i < n; ++i) {
        index[0][i] = a[i].first - (a[i].second - 1);
        index[1][i] = a[i].first - (a[i].second - 1) - 1;
        rem[i] = a[i].second / 2;
        rem1[i] = (a[i].second + 1) / 2;
    }

    string fans;
    vector<int> rank;
    vector<int> skip;

    auto calcIndexes = [&](int pos) {
        for (int u = 0; u < 2; ++u) {
            int v = index[u][pos];
            int ind = 0;
            if (u == 0 && rem[pos] == 0) {
                continue;
            }

            while (true) {
                if (ind < 0 || ind >= SZ(rank)) {
                    throw 1;
                }
                if (rank[ind] > pos) {
                    ind = skip[ind];
                } else if (skip[ind] - ind <= v) {
                    v -= skip[ind] - ind;
                    ind = skip[ind];
                } else {
                    ind += v;
                    break;
                }
            }

            index[u][pos] = ind;
        }
    };
    auto addChars = [&](int pos, int cSkip) {
        int u;
        if (rem[pos] > 0) {
            u = 0;
            rem[pos]--;
        } else {
            u = 1;
            rem1[pos]--;
        }
        char c = fans[index[u][pos]];
        fans += c;
        rank.push_back(pos);
        skip.push_back(cSkip);
        if ((u == 1 && rem1[pos] > 0) || (u == 0 && rem[pos] > 0)) {
            for (int _ = 0; _ < 2; ++_) {
                index[u][pos]++;
                while (rank[index[u][pos]] > pos) {
                    index[u][pos] = skip[index[u][pos]];
                }
            }
        }
    };

    vector<int> stk;
    int pos = 0;
    while (SZ(fans) < k) {
        if (stk.empty()) {
            if (pmin == -1 || k - SZ(fans) < a[pmin].first) {
                while (SZ(fans) < k) {
                    fans += s[pos++];
                    buckets[0] += s[pos - 1];
                    skip.push_back(-1);
                    rank.push_back(-1);
                }
            } else {
                int v = a[pmin].first;
                for (int i = 0; i < n; ++i) {
                    a[i].first -= v;
                }
                int cSkip = SZ(fans) + v;
                while (v-- > 0 && SZ(fans) < k) {
                    fans += s[pos++];
                    skip.push_back(cSkip);
                    rank.push_back(-1);
                    buckets[0] += s[pos - 1];
                }
                stk.push_back(pmin);
                calcIndexes(pmin);
                pmin = -1;
                for (int i = n - 1; i > stk.back(); --i) {
                    if (pmin == -1 || a[i].first < a[pmin].first) {
                        pmin = i;
                    }
                }
            }
        } else {
            if (pmin == -1 || a[stk.back()].second < a[pmin].first) {
                int v = a[stk.back()].second;
                for (int i = stk.back() + 1; i < n; ++i) {
                    a[i].first -= v;
                }
                a[stk.back()].second -= v;
                int cSkip = SZ(fans) + v;
                while (v-- > 0 && SZ(fans) < k) {
                    int p = stk.back();
                    addChars(p, cSkip);
                }
                while (!stk.empty() && a[stk.back()].second == 0) {
                    a[stk.back()].first = INF;
                    stk.pop_back();
                    pmin = -1;
                    int lim = stk.empty() ? -1: stk.back();
                    for (int i = n - 1; i > lim; --i) {
                        if (pmin == -1 || a[i].first < a[pmin].first) {
                            pmin = i;
                        }
                    }
                    if (pmin != -1 && a[pmin].first == 0) {
                        stk.push_back(pmin);
                        calcIndexes(pmin);
                        pmin = -1;
                        for (int i = n - 1; i > stk.back(); --i) {
                            if (pmin == -1 || a[i].first < a[pmin].first) {
                                pmin = i;
                            }
                        }
                    }
                }
            } else {
                int v = a[pmin].first;
                for (int i = stk.back() + 1; i < n; ++i) {
                    a[i].first -= v;
                }
                a[stk.back()].second -= v;
                int cSkip = SZ(fans) + v;
                while (v-- > 0 && SZ(fans) < k) {
                    int p = stk.back();
                    addChars(p, cSkip);
                }
                stk.push_back(pmin);
                calcIndexes(pmin);
                pmin = -1;
                for (int i = n - 1; i > stk.back(); --i) {
                    if (pmin == -1 || a[i].first < a[pmin].first) {
                        pmin = i;
                    }
                }
            }
        }
    }
    return fans;
}

vector<pair<int, int>> gen(int range, int n) {
    vector<pair<int, int>> ret;
    for (int i = 1; i <= n; ++i) {
        int l = rand() % range + 1;
        int r = rand() % range + 1;
        if (l > r) {
            swap(l, r);
        }
        ret.push_back(make_pair(l, r));
        // range += r - l + 1;
    }
    return ret;
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    // srand(time(0));

    // int cnt = 0;
    // while (true) {
    //     if (++cnt % 100 == 0) {
    //         cerr << "Done " << cnt << " tests" << endl;
    //     }
    //     string s = "ABCDE";
    //     vector<pair<int, int>> a = gen(2, 2);
    //     int total = SZ(s);
    //     for (const pair<int, int>& p: a) {
    //         total += p.second - p.first + 1;
    //     }
    //     string expected = brute(s, min(SZ(a), 100), total, a);
    //     string have;
    //     try {
    //         have = solve(s, min(SZ(a), 100), total, a);
    //     } catch(...) {

    //     }
    //     if (expected != have) {
    //         cerr << "Wrong on:" << endl;
    //         cerr << s << endl;
    //         cerr << total << endl;
    //         cerr << SZ(a) << endl;
    //         for (const pair<int, int>& p: a) {
    //             cerr << p.first << ' ' << p.second << endl;
    //         }
    //         cerr << "Expected: " << expected << endl;
    //         cerr << "Got: " << have << endl;
    //         break;
    //     }
    // }
    // return 0;

    string s;
    cin >> s;

    int k, n;
    cin >> k >> n;

    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }

    cout << solve(s, n, k, a) << '\n';

}