#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cstring>
#include <cassert>
#include <ctime>


using namespace std;
#define forn(i, n) for(int i = 0; i < n; i++)
#define forab(i, a, b) for(int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

typedef long long ll;
typedef vector < int > vi;

const int maxn = 2e5;
const int inf = 1e9;

char s[maxn];

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int n;
    bool flag = 0;
    scanf("%s", s);
    n = strlen(s);
    for(int i = 0; i < n - 1; i++){
        if (!flag && s[i] == '0')
            flag = 1;
        else
            printf("%c", s[i]);
    }
    if (flag)
        printf("%c", s[n - 1]);
    cerr << endl;
    return 0;
}