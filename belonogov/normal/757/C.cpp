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
#include <stdlib.h>
#include <random>


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
#define hash hashh
#define less lesss
const int N = 1e6 + 1;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int MOD = 1e9 + 7;

int n, m;
ull hash[N];
ull rnd[N];
ll fact[N];
mt19937 rr(4);

void read() {
    scanf("%d%d", &n, &m);
    srand(8);
    for (int i = 0; i < n; i++) {
        //rnd[i] = i * 143412351ll + 9082739487ll;
        rnd[i] = rr() * pw(30) + rr();
        //rnd[i] = rand() * 1290381203ll + rand() * 1390182301983ll + rand();

        //
        //
        //rnd[i] = rand() * pw(45) + rand() * pw(30) + rand() * pw(15) + rand();
        //rnd[i] = rand() * pw(15) + rnd() + rand() * pw(30) + rand() * pw(45); 
        //rnd[i] = lrand48() * pw(30) + lrand48();
        //db(rnd[i]);
    }
    //db(rnd[2]);

    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            int x;
            scanf("%d", &x); x--;
            hash[x] += rnd[i];
        }
    }
    fact[1] = 1;
    for (int i = 2; i <= m; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    map<ull,int> q;
    for (int i = 0; i < m; i++) {
        q[hash[i]]++;
    }
    ll answer = 1;
    for (auto x: q) {
        answer = (answer * fact[x.S]) % MOD;
    }
    cout << answer << endl;
}

void solve() {

}

void stress() {

}

int main(){
#ifdef HOME 
    freopen("in", "r", stdin);
#endif
    if (1) {
        read();
        solve();
    }
    else {
        stress();
    }

    return 0;
}