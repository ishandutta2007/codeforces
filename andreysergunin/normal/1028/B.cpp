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
typedef pair<int, int> pii;
typedef long double ld;
typedef unsigned int uint;
typedef complex<double> Complex;

mt19937 rnd(random_device{}());

template<class T>
void print(const vector<T> &arr) {
    for (T a : arr)  {
        cout << a << " ";
    }
    cout << endl;
}

void precalc() {

}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;


    string s = "5";
    string t = "5";
    int y = 5;

    while (y < n) {
        s += '5';
        t += '4';
        y += 4;
    }
    reverse(all(s));
    reverse(all(t));

    cout << s << endl;
    cout << t << endl;

}