#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>

using namespace std;

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))

#define equal equalll
#define less lesss
const int N = 2e5 + 10;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

char s[N];
char t[N];
int a[N];
bool used[N];
int n, m;

bool check(int k) {
    memset(used, 0, sizeof(used)); 
    for (int i = 0; i < k; i++)
        used[a[i]] = 1;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        if (cur < m && t[i] == s[cur]) {
            cur++;
        }
    }
    return cur == m; 
}

int main(){
#ifdef HOME 
    freopen("in", "r", stdin);
#endif
    scanf("%s", t);
    scanf("%s", s);
    n = strlen(t);
    m = strlen(s);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        a[i]--;
    }
    int l = 0;
    int r = n - m + 1;
    while (r - l > 1) {
        if (check((l + r) / 2))
            l = (l + r) / 2; 
        else
            r = (l + r) / 2;
    }
    cout << l << endl;



    return 0;
}