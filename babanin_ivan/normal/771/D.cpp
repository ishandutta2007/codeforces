#pragma comment (linker, "/STACK:128000000")
#include <iostream>
#include <cstdio>
#include <fstream>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <bitset>
#include <ctime>
#include <sstream>
#include <stack>
#include <cassert>
#include <list>
#include <deque>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

typedef long long li;
typedef long long i64;
typedef pair <int, int> pi;
typedef vector <int> vi;
typedef double ld;
typedef vector<int> vi;
typedef pair <int, int> pi;

void solve();

//int timer = 0;
#define FILENAME ""

int main() {
    string s = FILENAME;
#ifdef YA
    //assert(!s.empty());
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    //cerr<<FILENAME<<endl;
    //assert (s != "change me please");
    clock_t start = clock();
#else
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen(FILENAME ".in", "r", stdin);
    //freopen(FILENAME ".out", "w", stdout);
    cin.tie(0);
#endif
    cout.sync_with_stdio(0);
    cout.precision(10);
    cout << fixed;
    int t = 1;
    
    //cin >> t;
    for (int i = 1; i <= t; ++i) {
        //++timer;
        //cout << "Case #" << i << ": ";
        solve();
    }
#ifdef YA
    cerr << "\n\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n\n";
#endif
    return 0;
}

void solve() {
    int n;
    cin >> n;
    vector <int> a;
    
    a.push_back(2);
    
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        if (c == 'V') {
            a.push_back(0);
        } else if (c == 'K') {
            a.push_back(1);
        } else {
            a.push_back(2);
        }
    }
    vector <int> count(3);
    for (int x: a) {
        ++count[x];
    }
    
    vector <vector <vector <vector <int> > > > dp(a.size() + 1, vector <vector <vector <int> > > (3, vector <vector <int> > (a.size() + 1, vector <int> (a.size() + 1, -1))));
    
    dp[1][2][0][0] = 0;
    
    vector <int> tmp;
    tmp.reserve(2 * a.size());
    
    int global_ans = -1;
    
    for (int len_put = 1; len_put < a.size(); ++len_put) {
        for (int last = 0; last < 3; ++last) {
            vector <int> num(3);
            for (num[0] = 0; num[0] <= count[0]; ++num[0]) {
                for (num[1] = 0; num[1] <= count[1]; ++num[1]) {
                    num[2] = len_put - num[0] - num[1];
                    if (num[2] < 0 || num[2] > count[2]) {
                        continue;
                    }
                    if (num[last] == 0) {
                        continue;
                    }
                    int cur_val = dp[len_put][last][num[0]][num[1]];
                    if (cur_val == -1) {
                        continue;
                    }
                    vector <int> p = num;
                    vector <int> first_pos(3, -1);
                    int not_deleted = 0;
                    
                    int put_first_pos = 0;
                    
                    for (int i = 0; i < a.size() && put_first_pos < 3; ++i) {
                        if (p[a[i]] > 0) {
                            --p[a[i]];
                        } else {
                            if (first_pos[a[i]] == -1) {
                                first_pos[a[i]] = not_deleted;
                                put_first_pos++;
                            }
                            not_deleted++;
                        }
                    }
                    
                    for (int j = 0; j < 3; ++j) {
                        if (!(last == 0 && j == 1) && first_pos[j] != -1) {
                            int new_val = cur_val + first_pos[j];
                            int& to_upd = dp[len_put + 1][j][num[0] + int(j == 0)][num[1] + int(j == 1)];
                            if (to_upd == -1 || to_upd > new_val) {
                                to_upd = new_val;
                                
                                if (len_put + 1 == a.size()) {
                                    if (global_ans == -1 || global_ans > new_val) {
                                        global_ans = new_val;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    cout << global_ans << endl;
}