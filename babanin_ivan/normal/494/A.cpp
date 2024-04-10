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

void printerr() {
    cout << -1 << endl;
    exit(0);
}

void solve() {
    string s;
    cin >> s;
    vector <int> st1, st2;
    
    vector <int> ans;

    int pointer = 0;
    int m = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '#') {
            ++m;
        }
    }
    ans.resize(m);
    int cur = 0;


    int bal = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            ++bal;
        }
        if (s[i] == ')') {
            if (bal) {
                --bal;
            }
            else {
                while (pointer < cur && ans[pointer] == 1) {
                    ++pointer;
                }
                if (pointer == cur) {
                    printerr();
                }
                --ans[pointer];
            }
        }
        if (s[i] == '#') {
            ++cur;
            if (bal) {
                ans[cur - 1] = bal;
                bal = 0;
            }
            else {
                while (pointer < cur - 1 && ans[pointer] == 1) {
                    ++pointer;
                }
                if (pointer == cur - 1) {
                    printerr();
                }
                --ans[pointer];
                ans[cur - 1] = 1;
            }
        }
    }
    
    if (bal) {
        printerr();
    }

    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << "\n";
    }
}