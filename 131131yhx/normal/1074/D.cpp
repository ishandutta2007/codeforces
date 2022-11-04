#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <queue>
#include <bitset>
#include <cmath>
//#include <hash_map>
#define SIT set <int>::iterator

using namespace std;

int q, lans = 0;

map <int, int> Fa;
set <int> hsh[800010];
map <int, int> Num;
map <int, int> mm;

int getf(int x) {return !Fa[x] ? x : Fa[x] = getf(Fa[x]);}

void print(int x) {
    printf("%d\n", x);
    if(x == -1) lans = 1; else lans = x;
}

int ccnt = 0;

int main() {
    scanf("%d", &q);
    while(q--) {
        int op, l, r, x;
        scanf("%d%d%d", &op, &l, &r), l ^= lans, r ^= lans;
        if(l > r) swap(l, r);
        l++, r += 2;
        if(op == 1) {
            scanf("%d", &x);
            x ^= lans;
            if(getf(l) != getf(r)) {
                int gl = getf(l), gr = getf(r);
                if(!mm.count(gl)) mm[gl] = ++ ccnt;
                if(!mm.count(gr)) mm[gr] = ++ ccnt;
                gl = mm[gl], gr = mm[gr];
                if(hsh[gl].size() < hsh[gr].size()) swap(r, l), swap(gl, gr);
                if(hsh[gl].empty()) hsh[gl].insert(l);
                if(hsh[gr].empty()) hsh[gr].insert(r);
                int det = Num[l] ^ Num[r] ^ x;
                for(SIT it = hsh[gr].begin(); it != hsh[gr].end(); it++)
                    Num[*it] ^= det;
                hsh[gl].insert(hsh[gr].begin(), hsh[gr].end());
                Fa[getf(r)] = getf(l);
            }
        } else {
            if(getf(l) != getf(r)) print(-1);
            else print(Num[r] ^ Num[l]);
        }
    }
    return 0;
}