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

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout); 

    int n;
    cin >> n;

    vector<int> a(2 * n);

    for (int i = 0; i < 2 * n; ++i) {
        cin >> a[i];
        --a[i];
    }

    int res = 0;

    for (int i = 0; i < 2 * n; i += 2) {
        for (int j = 2 * n - 1; j > i + 1; --j) {
            if (a[j] == a[i]) {
                swap(a[j], a[j - 1]);
                ++res;
            }
        }  
    }

    cout << res << endl;


    
    return 0;
}