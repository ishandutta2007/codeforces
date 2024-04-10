// MIPT Shock Content
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
#include <complex>
#include <bitset>
 
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

mt19937 rr(random_device{}());

int main() {

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> p(n);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    set<pair<int, int>> setik;
    vector<bool> used(n);
    for (int i = 0; i < n; ++i) {
        auto it = setik.begin();
        if (!setik.empty() && it->first < p[i]) {
            if (!used[it->second]) {
                setik.erase(it);
            } else {
                used[it->second] = 0;
            }
            used[i] = 1;
            ans += p[i] - it->first;
        } 
        setik.insert({p[i], i});
    }
    cout << ans << endl;
}