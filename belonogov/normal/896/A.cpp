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
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))
#define equal equalll
#define less lesss

typedef double dbl;
typedef long long ll;
const int N = 1e5 + 10;
const ll INF = 1.01e18;
typedef vector<int> vi;


string s = "What are you doing at the end of the world? Are you busy? Will you save us?";
string b1 = "What are you doing while sending \"";
string b2 = "\"? Are you busy? Will you send \"";
string b3 = "\"?";
ll len[N];


char get(int n, ll& k) {
    if (len[n] < k) {
        //db("WORK");
        k -= len[n];
        return 0;
    }
    if (n == 0) {
        if (k < sz(s)) {
            ll pos = k;
            k = -1;
            return s[pos];
        }    
        else {
            k -= sz(s);
            return 0;
        }
    }
    if (k < sz(b1)) {
        ll pos = k;
        k = -1;
        return b1[pos];
    }

    k -= sz(b1);
    auto ch = get(n - 1, k);
    if (k == -1) return ch;

    if (k < sz(b2)) {
        ll pos = k;
        k = -1;
        return b2[pos];
    }
    k -= sz(b2);


    ch = get(n - 1, k);
    if (k == -1) return ch;


    if (k < sz(b3)) {
        ll pos = k;
        k = -1;
        return b3[pos];
    }
    k -= sz(b3);
    return 0;
}

int main() {
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    len[0] = s.size();
    for (int i = 1; i < N; i++) {
        len[i] = len[i - 1] * 2 + b1.size() + b2.size() + b3.size();
        if (len[i] > INF) {
            len[i] = INF;
        }
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        ll n, k;
        cin >> n >> k;
        k--;     
        auto ch = get(n, k);
        if (k != -1) {
            ch = '.';
        }
        printf("%c", ch);
        


    }
    puts("");

    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}