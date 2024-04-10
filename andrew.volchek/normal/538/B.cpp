#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <ctype.h>
#include <cassert>
#include <stack>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <functional>
#include <ctime>

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left
#define right _right

const ld pi = 3.14159265359;

template<typename T>
T abs(T x) {
    return x > 0 ? x : -x;
}

template<typename T>
T sqr(T x) {
    return x * x;
}




int main() {
    srand(time(NULL));

#ifdef LOCAL
    //gen();
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    string x;
    cin >> x;

    vector<string> ans;

    while (true) {
        bool any = false;
        string curr = "";
        for (char &ch : x) {
            if (any || ch > '0') {
                any = true;
                curr += (ch > '0') ? '1' : '0';
                if (ch > '0') {
                    ch--;
                }
            }
        }
        if (!any) {
            break;
        }
        ans.pb(curr);
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        if (i) {
            cout << " ";
        }
        cout << ans[i];
    }

    return 0;
}