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

int n;
map<string,int> q;

void read() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        int x;
        cin >> s >> x;
        q[s] = max(q[s], x);
    }
    vector<pair<int,string>> tmp;
    for (auto x: q)
        tmp.pb(mp(x.S, x.F));

    sort(all(tmp));

    n = q.size();
    cout << n << endl;
    for (int i = 0; i < n; ) {
        int j = i;
        for (; i < n && tmp[i].F == tmp[j].F; i++);

        int better = n - i;
        string type;
        if (better * 2 > n) {
            type = "noob";
        }
        else if (better * 5 > n) {
            type = "random";
        }
        else if (better *  10 > n) {
            type = "average";
        }
        else if (better * 100 > n) {
            type = "hardcore";
        }
        else
            type = "pro";
        for (; j < i; j++)
            cout << tmp[j].S << " " << type << endl;
    }


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