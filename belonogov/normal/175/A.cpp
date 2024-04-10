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
#include <sstream>

using namespace std;

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))

#define equal equalll
#define less lesss
const int N = -1;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

string s;

int get(string tmp) {
    stringstream g(tmp);
    if (tmp.size() > 7 || (tmp[0] == '0' && tmp.size() > 1))
        return -INF;
    int x;
    g >> x;
    if (x > 1e6)
        return -INF;
    return x;
}

void read() {
    cin >> s; 
    ll best = -1;
    for (int len1 = 1; len1 < (int)s.size(); len1++) {
        for (int len2 = 1; len2 + len1 < (int)s.size(); len2++) {
            stringstream tmp(s.substr(0, len1)); 
            int a = get(s.substr(0, len1));
            int b = get(s.substr(len1, len2));
            int c = get(s.substr(len1 + len2, s.size() - len1 - len2));
            ll h = a * 1ll + b + c;
            best = max(h, best);
        }

    }
    cout << best << endl;


}

void solve() {

}

void stress() {

}

int main(){
#ifdef HOME 
    freopen("in", "r", stdin);
#endif
    if (1) {
        read();
        solve();
    }
    else {
        stress();
    }

    return 0;
}