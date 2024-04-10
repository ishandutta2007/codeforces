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

string s;
int pi[2000000];
int64 h[2000000];
int64 p[2000000];


int64 gethash(int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    char c;
    while (scanf("%c", &c) == 1) {
        if ((c >= 'a') && (c <= 'z'))
            s.pb(c);
    }

    int n = s.length();

    for (int i=1; i<n; ++i) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])  ++j;
        pi[i] = j;
    }
    int maxx = 0;
    for (int i = 1; i < n - 1; ++i)
        maxx = max(maxx, pi[i]);
    h[0] = 0;
    for (int i = 1; i <= n; ++i)
        h[i] = h[i - 1] * int64(997) + int64(s[i - 1]);
    p[0] = 1;
    for (int i = 1; i <= n + 100; ++i)
        p[i] = p[i - 1] * int64(997);

    int ans = 0;
    for (int i = 1; i <= maxx; ++i) {
        if (gethash(1, i) == gethash(n - i + 1, n))
            ans = i;
    }
    for (int i = 0; i < ans; ++i)
        printf("%c", s[i]);
    if (ans == 0)
        printf("Just a legend\n");
    return 0;
}