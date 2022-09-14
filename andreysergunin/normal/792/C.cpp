#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <cstring>
#include <complex>
#include <bitset>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
mt19937 rr(random_device{}());

const int INF = 2e9 + 10;

string solve(string s) {
    int sum = 0;
    int n = sz(s);
    for (int i = 0; i < n; ++i) 
        sum += s[i] - '0';
    sum %= 3;
    if (sum == 0)
        return s;
    for (int i = 1; i < n; ++i) {
        if (sum == (s[i] - '0') % 3) {
            s.erase(i, 1);
            return s;
        }
    }

    int d = 3 - sum;
    vector<int> pos;

    for (int i = 1; i < n; ++i) {
        if (d == (s[i] - '0') % 3) {
            pos.push_back(i);
        }
    }

    if (sz(pos) >= 2) {
        s.erase(pos[1], 1);
        s.erase(pos[0], 1);
        return s;
    }

    return "";
}

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    int n = sz(s);

    int cnt = 0;
    string res = "";
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0' && res == "") {
            res = "0";
        }
        if (s[i] != '0' && cnt < 3) {
            ++cnt;
            string tmp = solve(s.substr(i, n - i));

            if (sz(res) < sz(tmp))
                res = tmp;
        }   
    }
    cout << (res == "" ? "-1" : res) << endl;

}