#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>
#include <bitset>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;
typedef long double ldouble;

using namespace std;

struct Node {
    Node* ch[2] = {0, 0};
    int cnt = 0;
};

Node* root = new Node();

void add(int x) {
    Node* cur = root;
    for (int i = 30; i >= 0; i--) {
        int b = (x >> i) & 1;
        if (cur->ch[b] == 0) {
            cur->ch[b] = new Node();
        }
        cur = cur->ch[b];
        cur->cnt++;
    }
}

void remove(int x) {
    Node* cur = root;
    for (int i = 30; i >= 0; i--) {
        int b = (x >> i) & 1;
        Node* nx = cur->ch[b];
        nx->cnt--;
        if (nx->cnt == 0) {
            cur->ch[b] = 0;
        }
        cur = nx;
    }
}

int get_mx(int x) {
    int res = 0;
    Node* cur = root;
    for (int i = 30; i >= 0; i--) {
        int b = (x >> i) & 1;
        if (cur->ch[1 - b] != 0) {
            res |= 1 << i;
            cur = cur->ch[1 - b];
        } else {
            cur = cur->ch[b];
        }
        if (cur == 0) {
            break;
        }
    }
    return res;
}

int main() {
    init_cin;
    int q;
    cin >> q;
    add(0);
    while (q-- > 0) {
        string s;
        int x;
        cin >> s >> x;
        if (s == "+") {
            add(x);
        } else if (s == "-") {
            remove(x);
        } else {
            cout << get_mx(x) << "\n";
        }
    }

    return 0;
}