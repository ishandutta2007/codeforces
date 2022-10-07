#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define fr first
#define sc second
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define next Nexttttttttttt

const int maxn = -1;
const long long p = 1e9 + 7;

long long ans = 0;

int n, k;
int next[20];


inline void check(){
    bool flag, v;
    for(int i = 1; i < k; i++){
        flag = 0;
        v = i;
        for(int j = 0; j < k && !flag; j++){
            v = next[v];
            if (v == 0)
                flag = 1;
        }
        if (!flag) return;
    }
    ans++;
}

void rec(int t){
    if (t == k){
        check();
        return;
    }
    for(int i = 0; i < k; i++){
        next[t] = i;
        rec(t + 1);
    }
}


int main(){
    //freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
    cin >> n >> k;

    rec(1);
//    cerr << ans << endl;

    ans = (ans * k) % p;
    for(int i = k; i < n; i++)
        ans = (ans * (n - k)) % p;

    cout << ans << endl;
    return 0;

}