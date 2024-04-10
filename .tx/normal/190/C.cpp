#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>
#include <stack>
#include <sstream>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;

using namespace std;

string a[111111];

const string err = "Error occurred";

int main() {
    init_cin
    int n;
    cin >> n;
    int x = 0;
    while (cin >> a[x]) {
        x++;
    }
    if (x != 2 * n - 1) {
        cout << err;
        return 0;
    }
    if (n == 1) {
        cout << "int";
        return 0;
    }
    int cp = 0, ci = 0;
    for (int i = 0; i < x; i++) {
        if (ci > cp) {
            cout << err;
            return 0;
        }
        if (a[i] == "int") {
            ci++;
        } else {
            cp++;
        }
    }
    if (cp + 1 != ci) {
        cout << err;
        return 0;
    }
    stack<int> cc;
    stringstream ans;
    for (int i = 0; i < x; i++) {
        if (a[i] == "pair") {
            ans << "pair<";
            if (i == 0 || a[i - 1] == "pair") {
                cc.push(1);
            } else {
                cc.top()++;
            }
        } else {
            ans << "int";
            if (a[i - 1] != "pair") {
                int x = cc.top();
                cc.pop();
                for (int j = 0; j < x; j++) {
                    ans << ">";
                }
            }
            ans << ",";
        }
    }

    string s;
    ans >> s;
    cout << s.substr(0, s.length() - 1);

    return 0;
}