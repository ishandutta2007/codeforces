#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <sstream>
#include <list>
#include <time.h>
#include <math.h>
#include <cmath>

using namespace std;

typedef long long int ll;

typedef vector<int> vei;
typedef vector<ll> vell;

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define pri(a) printf("%d\n", a)
#define prisp(a) printf("%d ", a)

#define foi(stt) for (int i = 0; i < stt; ++i)
#define foj(stt) for (int j = 0; j < stt; ++j)

#define pb push_back

#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(a) (int)a.size()

#define openfiles(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)

const int MAXN = 1e5;

char st[MAXN];
int len = 0;

char back(char c) {
    return (c == '-' ? '+' : '-');
}

// File names!!!

int main() {
    // openfiles("test");
    string s;
    getline(cin, s);
    for (auto c : s) {
        if (len == 0) {
            st[len++] = c;
        } else {
            if (st[len - 1] == c) len--;
            else st[len++] = c;
        }
    }
    puts(len == 0 ? "Yes" : "No");

    return 0;
}