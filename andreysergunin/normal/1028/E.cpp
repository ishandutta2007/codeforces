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

const ll INF = 1e10;
const int P = 1e9 + 7;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<ll> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        // b[i] = rnd() % 1000;
    }   

    vector<ll> a(n, - 1);
    bool ok = false;

    for (int i = 0; i < n; ++i) {
        int j = (i + 1 == n ? 0 : i + 1);
        if (b[i] < b[j]) {
            a[j] = b[j];
            ok = true;
        }
    }


    

    if (!ok) {
        if (b[0] == 0) {
            cout << "YES" << endl;
            for (int i = 0; i < n; ++i) {
                cout << 1 << " ";
            }
            cout << endl;
            return 0;
        }
        cout << "NO" << endl;
        return 0;
    } 

    // print(a);

    for (int i = 0; i < n; ++i) {
        int j = (i + 1 == n ? 0 : i + 1);
        if (a[j] != -1 && a[i] == -1) {
            int k = i;
            while (a[k] == -1) {
                a[k] = ((INF - 1) / a[j] + 1) * a[j] + b[k];
                j = k;
                k = (k == 0 ? n - 1 : k - 1);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        int j = (i + 1 == n ? 0 : i + 1);
        assert(a[i] % a[j] == b[i]);
    }

    cout << "YES" << endl;
    print(a);



}