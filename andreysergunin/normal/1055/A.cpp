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
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);


    int n, s;
    cin >> n >> s;
    --s;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    if (a[0] == 0) {
        cout << "NO" << endl;
        return 0;
    }

    if (a[s] == 1) {
        cout << "YES" << endl;
        return 0;
    }

    if (b[s] == 0) {
        cout << "NO" << endl;
        return 0;
    }

    for (int i = s + 1; i < n; ++i) {
        if (a[i] == 1 && b[i] == 1) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;




}