#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <random>
#include <functional>

using namespace std;

#define F first
#define S second
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << ": "; for (auto& xxxx: a) cerr << xxxx << " "; cerr << endl;
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))

#define equal equalll
#define less lesss
typedef long double dbl;
typedef long long ll;
const int N = -1;
const ll INF = 1.01e9;
typedef vector<int> vi;
const int MOD = 1e9 + 7;



int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    string s;
    cin >> s;
    int n = s.size();
    ll cntB = 0;
    ll answer = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'b') {
            cntB = (cntB + 1) % MOD;
        } 
        else {
            answer = (answer + cntB) % MOD;
            cntB = (cntB * 2) % MOD;
        }
    }
    cout << answer << endl;
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}