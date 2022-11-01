#include <iostream> 
#include <cstdio> 
#include <set> 
#include <map> 
#include <vector> 
#include <queue> 
#include <stack> 
#include <cmath> 
#include <algorithm> 
#include <cstring> 
#include <bitset> 
#include <ctime> 
#include <sstream>
#include <stack> 
#include <cassert> 
#include <list> 
//#include <unordered_set> 
using namespace std;
typedef long long int64;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define mp make_pair 
#define pb push_back 
#define all(s) s.begin(), s.end() 
void solve();

#define NAME "changemeplease"
int main() {
#ifdef YA 
    cerr << NAME << endl;
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout); 
    clock_t start = clock();
#else 
    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout); 
#endif 
    ios_base::sync_with_stdio(false);
    cout << fixed;
    cout.precision(10);
    int t = 1;
    //cin >> t;  
    while (t--)
        solve();

#ifdef YA 
    cout << "\n\n\nTime:" << ((clock() - start) / 1.0 / CLOCKS_PER_SEC);
#endif 
    return 0;
}

int n, k;
char res[1001][1001];

void print() {
    cout << n << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << res[i][j];
        }
        cout << "\n";
    }
    exit(0);
}

//int oldk;

int tmplast = 1;
int ttlast;

void add2(const vector <int>& aa) {
    int lastl = 0;
    int lastr = 0;
    for (int i = 0; i < aa.size(); ++i) {
        int curl = tmplast + 1;
        int curr = tmplast + aa[i];
        tmplast = curr;
        for (int j = lastl; j <= lastr; ++j) {
            for (int x = curl; x <= curr; ++x) {
                res[j][x] = res[x][j] = 'Y';
            }
        }
        lastl = curl;
        lastr = curr;
    }
    ttlast = tmplast + 1;
    tmplast++;
    for (int i = lastl; i <= lastr; ++i) 
        res[ttlast][i] = res[i][ttlast] = 'Y';
}


void add(int t) {
    int lastl = ttlast;
    int lastr = ttlast;

    for (int i = 0; i < 30; ++i) {
        int curl = tmplast + 1;
        int curr = tmplast + 2;
        if (i >= t)
            --curr;
        tmplast = curr;
        for (int j = curl; j <= curr; ++j) {
            for (int x = lastl; x <= lastr; ++x) {
                res[j][x] = res[x][j] = 'Y';
            }
        }
        lastl = curl;
        lastr = curr;
    }
    for (int i = lastl; i <= lastr; ++i) {
        res[1][i] = res[i][1] = 'Y';
    }
}

void solve() {  
    for (int i = 0; i < 1000; ++i)
        for (int j = 0; j < 1000; ++j) {
            res[i][j] = 'N';    
        }

    cin >> k;
    //oldk = k;
    if (k == 1) {
        n = 2;
        res[0][1] = res[1][0] = 'Y';
        print();
    }
    
    vector <int> b;
    for (int i = 2; i <= 300; ++i) {
        while (k % i == 0) {
            k /= i;
            b.push_back(i);
        }
    }
    add2(b);
    int cur = 0;

    while (k) {
        if (k & (1 << cur)) {
            add(cur);
            k -= (1 << cur);
        }
        ++cur;
    }
    n = tmplast + 1;
    print();
}