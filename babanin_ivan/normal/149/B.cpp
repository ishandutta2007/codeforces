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

string s1, s2;
vector <int> a1, a2;
vector <int> ans;

bool check(int x) {
    for (int i = 0; i < a1.size(); ++i)
        if (a1[i] >= x)
            return false;
    for (int i = 0; i < a2.size(); ++i)
        if (a2[i] >= x)
            return false;
    int t = 0;
    for (int i = 0; i < a1.size(); ++i)
        t = t * x + a1[i];
    if ((t >= 24) || (t < 0))
        return false;
    t = 0;
    for (int i = 0; i < a2.size(); ++i)
        t = t * x + a2[i];
    if ((t >= 60) || (t < 0))
        return false;
    return true;
}

void parse() {
    for (int i = 0; i < s1.size(); ++i) {
        if ((s1[i] >= '0') && (s1[i] <= '9'))
            a1.pb(s1[i] - '0');
        else a1.pb(s1[i] - 'A' + 10);
    }
    for (int i = 0; i < s2.size(); ++i) {
        if ((s2[i] >= '0') && (s2[i] <= '9'))
            a2.pb(s2[i] - '0');
        else a2.pb(s2[i] - 'A' + 10);
    }
    reverse(a1.begin(), a1.end());
    reverse(a2.begin(), a2.end());
    while ((a1.size() > 1) && (a1[a1.size() - 1] == 0))
        a1.pop_back();
    while ((a2.size() > 1) && (a2[a2.size() - 1] == 0))
        a2.pop_back();
    reverse(a1.begin(), a1.end());
    reverse(a2.begin(), a2.end());
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string s;
    cin >> s;
    int i = 0;
    while (s[i] != ':') {
        s1.pb(s[i]);
        ++i;
    }
    ++i;
    while (i < s.size()) {
        s2.pb(s[i]);
        ++i;
    }
    parse();
    for (int i = 2; i < 200; ++i)
        if (check(i))
            ans.pb(i);
    if (ans.size() > 100)
        cout << -1 << endl;
    else {
        //cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); ++i)
            printf("%d ", ans[i]);
    }
    if (ans.size() == 0)
        cout << 0 << endl;
    return 0;
}