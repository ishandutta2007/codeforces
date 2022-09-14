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

mt19937 rnd(random_device{}());

const ll INF = 1e18;

int request(int n) {
    cout << "? " <<  n + 1 << endl;
    int ans;
    cin >> ans;
    return ans;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    n /= 2;

    if (n % 2 == 1) {
        cout << "! " << -1 << endl;
        return 0; 
    }

    int a = request(0);
    int b = request(n);

    if (a == b) {
        cout << "! " << 1 << endl;
        return 0;
    } else if (a > b) {
        int l = 0, r = n;

        while (r - l > 1) {
            int mid = (l + r) / 2;
            int x = request(mid);
            int y = request(n + mid);
            if (x - y >= 0) {
                l = mid;
            } else {
                r = mid;
            }
        } 

        cout << "! " << l + 1 << endl;
        return 0;
    } else {
        int l = 0, r = n;

        while (r - l > 1) {
            int mid = (l + r) / 2;
            int x = request(mid);
            int y = request(n + mid);
            if (x - y <= 0) {
                l = mid;
            } else {
                r = mid;
            }
        } 

        cout << "! " << l + 1 << endl;
        return 0;
    }

    

    return 0;
}