#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <cmath>

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

const int maxn = 1e6;
const int inf = 1e9;

string s;
int a[maxn];
int n;

bool check(int m){
    int k = n;
    for(int i = 0; i < 26; i++)
        k -= (a[i] + m - 1) / m;
    return k >= 0;
}


int main(){
//    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    int cnt = 0, len;
    cin >> s;
    cin >> n;
    len = s.length();
    for (int i = 0; i < len; i++)
        a[s[i] - 'a']++;
    for (int i = 0; i < 26; i++)
        cnt += (a[i] > 0) ? 1 : 0;
    if (n < cnt){
        printf("-1\n");
        return 0;
    }
    int l = 0, r = len + 1;
    while (r - l > 1){
        if (check((l + r) / 2))
            r = (l + r) / 2;
        else
            l = (l + r) / 2;
    }
    printf("%d\n", r);
    int cnt2 = 0;
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < (a[i] + r - 1) / r; j++){
            printf("%c", char(i + 'a'));
            cnt2++;
        }
    for (int i = 0; i < n - cnt2; i++)
        printf("a");
    printf("\n");

    return 0;
}