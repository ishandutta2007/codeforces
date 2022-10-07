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
#define forn(i, n) for (int i = 0; i < (n); i++)
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))
#define equal equalll
#define less lesss

typedef double dbl;
typedef long long ll;
const int N = -1;
const int INF = 1.01e9;
typedef vector<int> vi;


int ask(string s) {
    cout << "? " << s << endl;
    int x;
    cin >> x;
    return x;
}

int answer(int pos0, int pos1) {
    cout << "! " << pos0 + 1 << " " << pos1  + 1<< endl;
    exit(0);
}


int main(){
    int n;
    cin >> n;
    string s(n, '0');
    int f1 = ask(s); 
    s[0] = '1';
    int f2 = ask(s); 
    int pos0 = -1;
    int pos1 = -1;

    if (f2 < f1) {
        pos1 = 0;
        int l = 1;
        int r = n;
        while (r - l > 1) {
            string t(n, '0');
            int mid = (l + r) / 2;
            forn(i, mid) {
                t[i] = '1'; 
            }
            int res = ask(t);
            if (f1 - mid == res) {
                l = mid;
            }
            else {
                r = mid;
            }
        }
        pos0 = l;
    }
    else {
        pos0 = 0;
        int l = 1;
        int r = n;
        while (r - l > 1) {
            string t(n, '0');
            int mid = (l + r) / 2;
            forn(i, mid) {
                t[i] = '1';
            }
            int res = ask(t);
            if (f1 + mid == res) {
                l = mid;
            }
            else {
                r = mid;
            }
        }
        pos1 = l;
    }


    answer(pos0, pos1);
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}