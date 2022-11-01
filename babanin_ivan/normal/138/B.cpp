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
int a[10];
int b[10], c[10];
int maxans = 0;
pair <int, int> res;
vector <int> ans[2];

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    getline(cin, s);
    for (int i = 0; i < s.size(); ++i)
        ++a[s[i] - '0'];
    for (int i = 0; i <= a[0]; ++i) {
        for (int j = 0; j < 10; ++j)
            b[j] = c[j] = a[j];
        b[0] = c[0] = a[0] - i;
        int t = i;
        if (maxans < t) {
            maxans = t;
            res = mp(i, 0);
        }
        for (int j = 1; j <= 9; ++j) 
            if (b[j] && c[10 - j]) {
                --b[j];
                --c[10 - j];
                t = i + 1;
                for (int j = 0; j < 10; ++j)
                    t += min(b[j], c[9 - j]);
                if (maxans < t) {
                    maxans = t;
                    res = mp(i, j);
                }
                ++b[j];
                ++c[10 - j];
            }
    }
    
    for (int i = 0; i < res.first; ++i) {
        ans[0].pb(0);
        ans[1].pb(0);
    }
    if (res.second) {
        ans[0].pb(res.sec);
        ans[1].pb(10 - res.sec);
        for (int j = 0; j < 10; ++j)
            b[j] = c[j] = a[j];
        b[0] = c[0] = a[0] - res.first;
        --b[res.second];
        --c[10 - res.second];
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < min(b[i], c[9 - i]); ++j) {
                ans[0].pb(i);
                ans[1].pb(9 - i);
            }
            int x = min(b[i], c[9 - i]);
            b[i] -= x;
            c[9 - i] -= x;
        }
    }
    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < b[i]; ++j)
            ans[0].pb(i);
    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < c[i]; ++j)
            ans[1].pb(i);
    for (int i = ans[0].size() - 1; i >= 0; --i)
        printf("%d", ans[0][i]);
    printf("\n");
    for (int j = ans[1].size() - 1; j >= 0; --j)
        printf("%d", ans[1][j]);
    return 0;
}