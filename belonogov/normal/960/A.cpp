#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define sz(a) (int)(a).size()
#define all(a) (a).begin(),a.end()
#define pw(x) (1LL<<(x))

#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << " = "; for (auto xxxx: a) cerr << xxxx << " "; cerr << endl

using namespace std;

typedef long long ll;
typedef double dbl;
const int INF = 1.01e9;



int main() {
#define TASK "A"
#ifdef HOME 
    assert(freopen(TASK".in", "r", stdin));
#endif
    string s;
    cin >> s;
    bool ok = 1; 
    for (int i = 0; i < sz(s) - 1; i++) {
        ok &= s[i] <= s[i + 1];
    }
    map<char,int> q;  
    for (auto ch: s) {
        q[ch]++;
    } 
    ok &= q['a'] >= 1;
    ok &= q['b'] >= 1;
    ok &= q['c'] == q['a']  || q['c'] == q['b'];
    if (ok) {
        puts("YES");
    }
    else {
        puts("NO");
    }



    return 0;
}