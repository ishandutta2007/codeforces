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
#include <random>
#include <functional>

using namespace std;

#define F first
#define S second
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
const int N = -1;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef double dbl;



int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> a(k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &a[i]);
    }
    vector<int> b;
    for (int i = 0; i < n; i++)
        b.pb(i);


    int pos = 0;
    for (int i = 0; i < k; i++) {
        //db(pos);
        int h = (pos + a[i]) % b.size();
        printf("%d ", b[h] + 1);
        b.erase(b.begin() + h);
        pos = h;
        if (pos == sz(b))
            pos = 0;
    }

    puts("");


    
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}