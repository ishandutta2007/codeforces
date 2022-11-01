#pragma comment (linker, "/STACK:128000000")
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

using namespace std;

#define mp make_pair
#define pb push_back

typedef long long li;
typedef long long i64;
typedef pair <int, int> pi;
typedef vector <int> vi;
typedef double ld;
typedef vector<int> vi;
typedef pair <int, int> pi;

void solve();

//int timer = 0;
#define FILENAME ""

int main() {
    string s = FILENAME;
#ifdef YA
    //assert(!s.empty());
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //cerr<<FILENAME<<endl;
    //assert (s != "change me please");
    clock_t start = clock();
#else
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen(FILENAME ".in", "r", stdin);
    //freopen(FILENAME ".out", "w", stdout); 
    cin.tie(0);
#endif
    cout.sync_with_stdio(0);
    cout.precision(10);
    cout << fixed;
    int t = 1;
    
    //cin >> t;
    for (int i = 1; i <= t; ++i) {
        //++timer;
        //cout << "Case #" << i << ": ";
        solve();
    }
#ifdef YA
    cerr << "\n\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n\n";
#endif
    return 0;
}


int gcd(int x, int y) {
    if (x % y == 0) {
        return y;
    }
    return gcd(y, x % y);
}   

void solve() {
    int N = 10000000;

    vector <int> is_prime(N, 1);

    for (int i = 2; i < N; ++i) {
        if (is_prime[i]) {
            for (li j = li(i) * li(i); j < N; j += i) {
                is_prime[j] = 0;
            }
        }
    }

    vector <int> tmp;

    vector <int> is_rub(N, 1);

    for (int i = 1; i < N; ++i) {
        tmp.clear();
        int x = i;
        while (x) {
            tmp.push_back(x % 10);
            x /= 10;
        }
        int l = 0;
        int r = tmp.size() - 1;
        

        while (l < r) {
            if (tmp[l] != tmp[r]) {
                is_rub[i] = 0;
                break;
            }
            ++l;
            --r;
        }
    }
    /*
    int sum = 0;
    for (int i = 0; i < is_prime.size(); ++i) {
        sum += is_prime[i];
    }

    cout << sum << endl;

    int sum2 = 0;
    for (int t: is_rub) {
        sum2 += t;
    }
    cout << sum2 << endl;*/

    is_prime[0] = is_prime[1] = 0;
    is_rub[0] = 0;

    int p, q;
    cin >> p >> q;
    
    for (int i = 1; i < N; ++i) {
        is_prime[i] += is_prime[i - 1];
        is_rub[i] += is_rub[i - 1];
    }

    for (int i = N - 1; i >= 1; --i) {
        if (li(is_prime[i]) * q <= p * li(is_rub[i])) {
            cout << i << endl;
            return;
        }
    }
    cout << "Palindromic tree is better than splay tree\n";
}