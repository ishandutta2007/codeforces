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

const int inf = 2000000000;
const ld eps = 1e-07;

int n;

void printerr() {
    printf("NO\n");
    exit(0);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    if ((s1.size() + s2.size()) != s3.size())
        printerr();
    vector <char> a;
    vector <char> b;
    for (int i = 0; i < s1.size(); ++i)
        a.pb(s1[i]);
    for (int i = 0; i < s2.size(); ++i)
        a.pb(s2[i]);
    for (int i = 0; i < s3.size(); ++i)
        b.pb(s3[i]);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (a != b)
        printerr();
    else cout << "YES\n";
    return 0;
}