#include <iostream> 
#include <cstdio> 
#include <fstream>
#include <functional>
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
#include <deque>
//#include <unordered_set> 
using namespace std;
typedef long long li;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define mp make_pair 
#define pb push_back
#define y1 botva
#define all(s) s.begin(), s.end() 
void solve();

#define NAME "changemeplease"
int main() {
#ifdef YA 
    //cerr << NAME << endl;
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
    for (int i = 1; i <= t; ++i) {
        //cout << "Case #" << i << ": ";
        solve();
    }
#ifdef YA 
    //cout << "\n\n\nTime:" << ((clock() - start) / 1.0 / CLOCKS_PER_SEC);
#endif 
    return 0;
}

int n;

int getP(int x, int y) {
    li res = 1;
    if (y == 0) {
        return res;
    }
    if (y & 1) {
        return (li(x) * getP(x, y - 1)) % n;
    }
    li tmp = li(getP(x, y / 2));
    return  (tmp * tmp) % n;
}

int gcd(int x, int y) {
    if (x % y == 0) {
        return y;
    }
    return gcd(y, x % y);
}

void solve() {
    cin >> n;

    if (n == 1) {
        cout << "YES\n1\n";
        return;
    }

    bool f = false;
    for (int i = 2; i <= int(sqrt(n * 1.0) + 5) && i < n; ++i) {
        if (n == i * i) {
            f = true;
            break;
        }
        if (n % i == 0) {
            cout << "NO\n";
            return;
        }
    }

    

    vector <int> a;
    a.push_back(1);

    
    int cur = 1;
    if (!f) {
        for (int i = 2; i <= n - 1; ++i) {
            cur = li(i) * getP(i - 1, n - 2) % n;
            a.push_back(cur);
            //cerr << i << endl;
        }
    }
    else {

        /*if (n != 4) {
            cout << "NO\n";
            return;
        }*/
        int t = 1;
        for (int i = 2; i < n; ++i) {
            if (gcd(i, n) == 1) {
                ++t;
            }
        }

        int cur;
        int last = 1;
        for (int i = n - 1; i >= 2; --i) {
            cur = li(i) * getP(last, t - 1) % n;
            a.push_back(cur);
            last = i;
            //cerr << i << endl;
        }
    }

    a.push_back(n);
    vector <int> b;
    b = a;

    sort(a.begin(), a.end());
    for (int i = 1; i < a.size(); ++i) {
        if (a[i] == a[i - 1] || (a[i] < 1)) {
            cout << "NO\n";
            return;
        }
    }
    a = b;
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        cout << a[i] << "\n";
    }

    sort(a.begin(), a.end());
    for (int i = 1; i < a.size(); ++i) {
        if (a[i] == a[i - 1] || (a[i] < 1)) {
            assert(false);
        }
    }
}