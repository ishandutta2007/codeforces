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
typedef pair<int, int> pii;
mt19937 rr(random_device{}());

const int P = 1e9 + 7;

bool request(int a, int b) {
    cout << "1 " << a << " " << b << endl;
    string ans;
    cin >> ans;
    return (ans == "NIE");
}

int solve(int l, int r, int x) {
    if (l == r)
        return l;
    int mid = (l + r - x) / 2;
    return (request(mid, mid + 1) ? solve(mid + 1, r, x) : solve(l, mid, x));
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    int x = solve(1, n, 1);
    int y = solve(1, x, 1);
    int z = solve(x + 1, n, 0);
    if (x != y) {
        cout << "2 " << x << " " << y << endl;
    } else {
        cout << "2 " << x << " " << z << endl;
    }
    
    

    
}