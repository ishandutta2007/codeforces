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

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");
    
    int k;
    cin >> k;
    if (k == 0) {
        cout << "a\n";
        return 0;
    }
    vector<int> prv(k + 1, -1), cnt(k + 1, 1000);
    prv[0] = 0;
    cnt[0] = 0;
    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j * (j - 1) / 2 <= i; ++j) {
             if (prv[i - j * (j - 1) / 2] >= 0 && cnt[i - j * (j - 1) / 2] + 1 < cnt[i]) {
                prv[i] = j;
                cnt[i] = cnt[i - j * (j - 1) / 2] + 1;
             }
        }
    }

    string s;
    int cur = 0;
    for (; k > 0; ) {
        for (int i = 0; i < prv[k]; ++i)
            s += (char)('a' + cur);
        k = k - prv[k] * (prv[k] - 1) / 2;
        ++cur;
    }
    cout << s << "\n";
}