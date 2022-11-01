#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>

using namespace std;

#define pb push_back
#define mp make_pair
#define fir first
#define fi first
#define sec second
#define y1 botva23
typedef long long int64;
typedef long double ld;

const int inf=2000000000;
const ld eps=1e-07;

int n;
set < pair<int, int> > a, a2;
vector <int> ans[3];
int bal = 0;
int maxx;

void print() {
    for (int t = 0; t < 2; ++t) {
        cout << ans[t].size() << endl;
        for (int i = 0; i < ans[t].size(); ++i)
            printf("%d ", ans[t][i]);
        cout << endl;
    }
    exit(0);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    scanf("%d", &n);
    maxx = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        a.insert(mp(x, i + 1));
        a2.insert(mp(x, i + 1));
        maxx = max(maxx, x);
    }
    
    ans[0].pb((*a.rbegin()).second);
    bal = (*a.rbegin()).first;
    a.erase(*a.rbegin());
    int t = 1;
    while (!a.empty()) {
        if (t == 0) {
            if (bal > 0) {
                pair <int, int> cur = *a.begin();
                ans[0].pb(cur.second);
                bal += cur.first;
                a.erase(cur);
            }
            else {
                pair <int, int> cur = *a.rbegin();
                ans[0].pb(cur.second);
                bal += cur.first;
                a.erase(cur);
            }
        }
        else {
            if (bal > 0) {
                pair <int, int> cur = *a.rbegin();
                ans[t].pb(cur.second);
                bal -= cur.first;
                a.erase(cur);
            }
            else {
                pair <int, int> cur = *a.begin();
                ans[t].pb(cur.second);
                bal -= cur.first;
                a.erase(cur);
            }
        }
        t = !t;
    }
    if (abs(bal) <= maxx)
        print();

    ans[0].clear();
    ans[1].clear();
    bal = 0;
    a = a2;



    ans[0].pb((*a.rbegin()).second);
    bal = (*a.rbegin()).first;
    a.erase(*a.rbegin());
    t = 0;
    while (!a.empty()) {
        if (t == 0) {
            if (bal > 0) {
                pair <int, int> cur = *a.begin();
                ans[0].pb(cur.second);
                bal += cur.first;
                a.erase(cur);
            }
            else {
                pair <int, int> cur = *a.rbegin();
                ans[0].pb(cur.second);
                bal += cur.first;
                a.erase(cur);
            }
        }
        else {
            if (bal > 0) {
                pair <int, int> cur = *a.rbegin();
                ans[t].pb(cur.second);
                bal -= cur.first;
                a.erase(cur);
            }
            else {
                pair <int, int> cur = *a.begin();
                ans[t].pb(cur.second);
                bal -= cur.first;
                a.erase(cur);
            }
        }
        t = !t;
    }
    print();
    return 0;
}