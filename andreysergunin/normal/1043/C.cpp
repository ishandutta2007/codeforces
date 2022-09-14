#include <iostream>
#include <stdio.h>
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
#include <bitset>
#include <functional>
#include <tuple>
#include <complex>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned int uint;

mt19937 rnd(random_device{}());

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    string s;
    cin >> s;
    int n = sz(s);

    string u, v;
    vector<int> a, b;
     
    for (int i = 0; i < n; ++i) {
        string u1 = u, u2 = u;
        u1 += s[i];
        u2 += s[i];
        reverse(all(u2));

        string v1 = v, v2 = v;
        v1 += s[i];
        v2 += s[i];
        reverse(all(v2));

        vector<int> aa, bb;

        if (u1 < v2) {
            u = u1;
            aa = a;
            aa.push_back(0);
        } else {
            u = v2;
            aa = b;
            aa.push_back(1);
        }

        reverse(all(v1));
        reverse(all(u2));

        if (v1 < u2) {
            v = v1;
            reverse(all(v));
            bb = b;
            bb.push_back(0);
        } else {
            v = u2;
            reverse(all(v));
            bb = a;
            bb.push_back(1);
        }

        a = aa;
        b = bb;
    }   

    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}