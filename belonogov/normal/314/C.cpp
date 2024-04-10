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

const int maxn = 1e6 + 10;
const int p = 1e9 + 7;
const int inf = 1e9;


int a[maxn];
map < int, int > b;
int next[maxn];
long long c[maxn];
long long tree[maxn];

void add(int pos, long long val){
    for(; pos < maxn; pos = pos | (pos + 1)){
        tree[pos] = (tree[pos] + val + p) % p;
        assert(tree[pos] >= 0);
    }
}

int getsum(int pos){
    int ans = 0;
    for(; pos >= 0; pos = (pos & (pos + 1)) - 1)
        ans = (ans + tree[pos]) % p;
    return ans;
}

int main(){
   // freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    int n;
    long long x;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(int i = n - 1; i >= 0; i--){
        if (b.find(a[i]) == b.end())
            next[i] = -1;
        else
            next[i] = b[a[i]];
        b[a[i]] = i;
    }
    add(0, 1);
    for(int i = 0; i < n; i++){
        x = getsum(a[i]);
        //epr("%d %d\n", i, (int)x);
        c[i] = (c[i] + x) % p;
     //   add(a[i], (- (getsum(a[i]) - getsum(a[i] - 1)) + p) % p);
        add(a[i], (c[i] * a[i]) % p);
        if (next[i] != -1)
            c[next[i]] = (c[next[i]] - x + p) % p;
    }
    cout << (getsum(1e6) - 1 + p) % p << endl;

    return 0;
}