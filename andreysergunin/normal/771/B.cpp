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

const int ALPH = 26;

string toString(int n) {
    string s;
    for (int i = 0; i < 5; ++i, n /= ALPH) {
        s += (char)(n % ALPH + 'a');
    }
    s[0] = s[0] + 'A' - 'a';
    return s;
}

int main() {
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<int> res(n);
    for (int i = 0; i < k - 1; ++i)
        res[i] = i;

    int cur = 0;
    cur = k - 2;
    for (int i = k - 1; i < n; ++i) {
        string s;
        cin >> s;
        if (s == "NO")
            res[i] = res[i - k + 1];
        else 
            res[i] = ++cur;
    }

    for (int i = 0; i < n; ++i)
        cout << toString(res[i]) << " ";
    cout << endl;

    return 0;
}