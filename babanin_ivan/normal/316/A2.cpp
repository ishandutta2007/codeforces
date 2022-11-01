#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

#define pb push_back
#define mp make_pair
typedef long long int64;
typedef long double ld;
const ld eps = 1e-09;
const int inf = 2000000000;

set <char> a;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string s;
    getline(cin, s);
    int z = 0;
    for (int i = 1; i < s.size(); ++i)
        if (s[i] == '?') 
            ++z;
        else if (s[i] >= 'A' && s[i] <= 'J')
                a.insert(s[i]);


    int64 tmp = 1;
    if (s[0] == '?')
        tmp = 9;
    int st = 10;
    if ((s[0] >= 'A') && (s[0] <= 'J')) {
        a.erase(s[0]);
        tmp = 9;
        st = 9;
    }
    for (int i = 0; i < a.size(); ++i)
        tmp = tmp * int64(st - i);

    cout << tmp;
    for (int j = 0; j < z; ++j)
        printf("0");
    return 0;
}