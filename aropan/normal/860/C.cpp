#include <iostream>
#include <cstdio>
#include <cassert>
#include <ctime>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#ifdef LOCAL
#define dbg(x) cerr << #x " = " << x << endl;
#else
#define dbg(x)
#endif

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

#define snd second
#define fst first

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
template <typename T> bool chmin(T &x, const T& y) { if (x > y) { x = y; return true; } return false; }
template <typename T> bool chmax(T &x, const T& y) { if (x < y) { x = y; return true; } return false; }

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif
    int n;
    while (cin >> n && n) {
        string name[n];
        int type[n];
        int e = 0;
        set <string> names;

        for (int i = 0; i < n; ++i) {
            cin >> name[i] >> type[i];
            e += type[i] == 1;
            names.insert(name[i]);
        }

        queue <string> files[2];
        map <string, int> tfile;
        for (int i = 1; i <= n; ++i) {
            string s = to_string(i);
            tfile[s] = i <= e? 1 : 0;
            if (names.count(s)) {
                continue;
            }
            files[tfile[s]].push(s);
        }

        queue <string> q[2];
        for (int i = 0; i < n; ++i) {
            if (tfile.count(name[i]) == 0) {
                continue;
            }
            if (type[i] == tfile[name[i]]) {
                continue;
            }
            q[type[i]].push(name[i]);
        }
        for (int i = 0; i < n; ++i) {
            if (tfile.count(name[i])) {
                continue;
            }
            q[type[i]].push(name[i]);
        }

        vector <pair<string, string>> answer;

        while (q[0].size() || q[1].size()) {
            if (files[0].size() + files[1].size() == 0) {
                auto& from = q[0].front();
                files[1].push(from);
                answer.emplace_back(from, "tmp");
                q[0].pop();
                q[0].push("tmp");
            }
            for (int i = 0; i < 2; ++i) {
                while (q[i].size() && files[i].size()) {
                    auto& from = q[i].front();
                    auto& to = files[i].front();
                    if (tfile.count(from) && tfile[from] != i) {
                        files[1 - i].push(from);
                    }
                    answer.emplace_back(from, to);
                    q[i].pop();
                    files[i].pop();
                }
            }
        }
        printf("%d\n", (int)answer.size());
        for (auto& p : answer) {
            printf("move %s %s\n", p.first.c_str(), p.second.c_str());
        }
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}