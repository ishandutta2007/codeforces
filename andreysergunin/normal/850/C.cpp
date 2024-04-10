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
#define sz(a) (int)(a).size()
#define pb push_back
 
using namespace std;

mt19937 rr(random_device{}());

typedef long  ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

map<int, vector<int>> cnt;
map<int, int> mp;

int f(int n, int k) {
    int x = n >> k;
    n ^= x << k;
    n |= x;
    return n;
}

int solve(int k) {
    if (mp.count(k))
        return mp[k];
    vector<int> to;
    for (int i = 1; (1 << i) <= k; ++i)
        to.push_back(solve(f(k, i)));
    sort(all(to));
    to.resize(unique(all(to)) - to.begin());

    for (int i = 0; i < sz(to); ++i) {
        if (to[i] != i)
            return mp[k] = i;
    }
    return mp[k] = sz(to);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");  

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)  {
        int a;
        cin >> a;
        for (int p = 2; p * p <= a; ++p) {
            if (a % p == 0) {
                int x = 0;
                for (; a % p == 0; a /= p, ++x);
                cnt[p].push_back(x);
            }
        }
        if (a > 1)
            cnt[a].push_back(1);
    }
    mp[1] = 0;
    int ans = 0;
    for (auto el : cnt) {
        vector<int> v = el.second;
        int mask = 0;
        for (int d : v)
            mask |= 1 << d;
        ans ^= solve(mask);
    }

    cout << (ans ? "Mojtaba" : "Arpa") << endl;
}