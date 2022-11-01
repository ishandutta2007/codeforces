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
#define all(a) a.begin(), a.end()

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
    freopen("output.txt", "w", stdout);
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

struct Student {
    int id_;
    int deg;
    Student(){}
    Student(int id_, int deg):id_(id_),deg(deg){}
};

bool comp(const Student& left, const Student& right) {
    if (left.id_ == right.id_) {
        return false;
    }
    
    if (left.id_ == 0 || right.id_ == 0) {
        if (left.id_ == 0) {
            return true;
        } else {
            return false;
        }
    }
    
    return left.deg > right.deg;
}

void solve() {
    int n;
    cin >> n;
    vector <Student> a(n);
    for (int i = 0; i < n; ++i) {
        a[i].id_ = i;
        cin >> a[i].deg;
    }
    
    sort(all(a), comp);
    
    vector <int> used(n);
    
    vector <pair <int, int> > ans;
    
    used[0] = true;
    for (int i = 0; i < a.size(); ++i) {
        if (used[a[i].id_]) {
            for (int j = i + 1; j < a.size(); ++j) {
                if (!used[a[j].id_] && a[i].deg) {
                    --a[i].deg;
                    used[a[j].id_] = true;
                    ans.push_back(mp(a[i].id_ + 1, a[j].id_ + 1));
                }
            }
        }
    }
    
    
    
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            cout << -1 << endl;
            exit(0);
        }
    }
    
    cout << ans.size() << endl;
    for (auto x: ans) {
        cout << x.first << " " << x.second << "\n";
    }
}