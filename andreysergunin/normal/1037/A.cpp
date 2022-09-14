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

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll n;
    cin >> n;

    ll k = 1;
    ll sum = 0;
    vector<ll> res;

    while (sum + k < n) {
        res.push_back(k);
        sum += k;
        k *= 2;
    } 

    if (sum != n) {
        res.push_back(n - sum);
    }

    cout << sz(res) << endl;
    // sort(all(res));
    // for (ll el : res) {
    //     cout << el << " ";
    // }
    // cout << endl;
}