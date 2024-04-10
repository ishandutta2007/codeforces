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

struct Node {
    int sum;
    Node* child[2];
    Node():sum(0){
        for (int i = 0; i < 2; ++i) {
            child[i] = nullptr;
        }
    }
};

Node* gen_new() {
    return new Node();
}

void generate(int x, Node* root, int val) {
    Node* cur = root;
    for (int i = 30; i >= 0; --i) {
        cur->sum += val;
        int r = bool((1 << i) & x);
        if (cur->child[r] == nullptr) {
            cur->child[r] = gen_new();
        }
        cur = cur->child[r];
    }
    cur->sum += val;
}

int find(int x, Node* root) {
    Node* cur = root;
    int result = 0;
    for (int i = 30; i >= 0; --i) {

        int r = bool((1 << i) & x);
        int chosen;

        if (cur->child[!r] != nullptr && cur->child[!r]->sum) {
            chosen = !r;
            result += (1 << i);
        }
        else {
            chosen = r;
        }

        cur = cur->child[chosen];
    }
    return result;
}

void solve() {
    Node* root = gen_new();
    generate(0, root, 1);
    int q;
    cin >> q;
    for (int i =0 ; i < q; ++i) {
        char c;
        cin >> c;
        int x;
        cin >> x;
        if (c == '+') {
            generate(x, root, 1);
        }
        if (c == '-') {
            generate(x, root, -1);
        }
        if (c == '?') {
            cout << find(x, root) << "\n";
        }

    }
}