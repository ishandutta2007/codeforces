#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cassert>
#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <random>
#include <iomanip>
#include <chrono>
#include <bitset>
#include <queue>
#include <complex>
#include <functional>
#include <unordered_map>

using namespace std;
int n;
int def_ans1, def_ans2;
string def_q1, def_q2;

inline int ask(const string& s) {
    cout << s << endl;
    int ans;
    cin >> ans;
    if (ans == n) exit(0);
    return ans;
}

void build_def() {
    for (int i = 0; i < n; ++i) {
        def_q1 += "T";
        if (i % 2 == 0) def_q2 += "T";
        else def_q2 += "F";
    }
    def_ans1 = ask(def_q1);
    def_ans2 = ask(def_q2);
}

inline int get_val(int i) {
    def_q1[i] ^= 'F' ^ 'T';
    int rs = ask(def_q1);
    def_q1[i] ^= 'F' ^ 'T';
    if (rs == def_ans1 + 1) return 0;
    else return 1;
}

inline int get_val2(int i, int j) {
    def_q1[i] ^= 'F' ^ 'T';
    def_q1[j] ^= 'F' ^ 'T';
    int rs = ask(def_q1);
    def_q1[i] ^= 'F' ^ 'T';
    def_q1[j] ^= 'F' ^ 'T';
    return rs - def_ans1;
}

inline int get_val3(int i) {
    def_q2[i] ^= 'F' ^ 'T';
    def_q2[i + 1] ^= 'F' ^ 'T';
    def_q2[i + 2] ^= 'F' ^ 'T';
    int rs = ask(def_q2);
    def_q2[i] ^= 'F' ^ 'T';
    def_q2[i + 1] ^= 'F' ^ 'T';
    def_q2[i + 2] ^= 'F' ^ 'T';
    return rs - def_ans2;
}

void solve1() {
    cin >> n;
    build_def();
    string answer;
    for (int i = 0; i < n; ++i) answer += "F";
    array <char, 2> flex = {'F', 'T'};
    for (int i = 0; i < n; ++i) {
        if (i + 2 < n) {
            int x = get_val2(i, i + 1);
            if (x == -2) {
                answer[i] = answer[i + 1] = 'T';
                answer[i + 2] = flex[get_val(i + 2)];
            } else if (x == 2) {
                answer[i] = answer[i + 1] = 'F';
                answer[i + 2] = flex[get_val(i + 2)];
            } else {
                int rs = get_val3(i);
                if (rs < 0) {
                    answer[i] = def_q2[i];
                    answer[i + 1] = def_q2[i + 1];
                } else {
                    answer[i] = def_q2[i] ^ 'F' ^ 'T';
                    answer[i + 1] = def_q2[i + 1] ^ 'F' ^ 'T';
                }
                if (rs == 1 || rs == -3) {
                    answer[i + 2] = def_q2[i + 2];
                } else {
                    answer[i + 2] = def_q2[i + 2] ^ 'F' ^ 'T';
                }
            }
            i += 2;
        } else {
            answer[i] = flex[get_val(i)];
        }
    }
    ask(answer);
}

signed main(int32_t argc, char **argv) {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    if (1) {
        int t = 1;
        //cin >> t;
        while (t--) {
            solve1();
        }
        //  while (true) {}
    } else {

    }
}

/*

 */