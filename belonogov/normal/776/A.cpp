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



int main(){
#ifdef HOME 
    freopen("in", "r", stdin);
#endif
    string s;
    string t;
    set<string> q;
    cin >> s >> t;
    q.insert(s);
    q.insert(t);
    int n;
    cin >> n;
    cout << s << " " << t << endl;
    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        q.erase(a);
        q.insert(b);
        for (auto x: q)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}