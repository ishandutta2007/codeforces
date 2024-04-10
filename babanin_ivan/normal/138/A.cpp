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

void printerr() {
    cout << "NO\n";
    exit(0);
}

bool is(char c) {
    if (c == 'a')
        return true;
    if (c == 'e')
        return true;
    if (c == 'i')
        return true;
    if (c == 'o')
        return true;
    if (c == 'u')
        return true;
    return false;
}
int n, k;

string getsuf(string s) {
    string res;
    res.clear();
    int m = 0;
    for (int i = s.size() - 1; i >= 0; --i) {
        if (is(s[i]))
            ++m;
        res.pb(s[i]);
        if (m == k)
            return res;
    }
    printerr();
}

string a[5];
bool used[5];

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    scanf("%d %d", &n, &k);
    used[0] = used[1] = used[2] = used[3] = true;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
            string s;
            scanf(" ");
            getline(cin, s);
            a[j] = getsuf(s);
        }
        if ((a[0] == a[1]) && (a[1] == a[2]) && (a[2] == a[3]))
            continue;
        int k = 0;
        used[0] = false;
        if (!((a[0] == a[1]) && (a[2] == a[3])))
            used[1] = false;
        if (!((a[0] == a[2]) && (a[1] == a[3])))
            used[2] = false;
        if (!((a[0] == a[3]) && (a[1] == a[2])))
            used[3] = false;
    }
    if (used[0])
        printf("aaaa\n");
    else if (used[1])
            printf("aabb\n");
    else if (used[2])
        printf("abab\n");
    else if (used[3])
        printf("abba\n");
    else printerr();
    return 0;
}