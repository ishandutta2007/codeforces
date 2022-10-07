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
#define dbv(a) cerr << #a << ": "; for (auto& xxxx: a) cerr << xxxx << " "; cerr << endl;
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))
#define equal equalll
#define less lesss

typedef long double dbl;
typedef long long ll;
const int N = 2222;
const ll INF = 1.01e9;
typedef vector<int> vi;
const int ALP = 26;

char s[N];


int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    vector<int> a(n);  
    for (int i = 0; i < n; i++)
        a[i] = s[i] - 'a';


    vector<vector<int>> opt(ALP, vector<int>(n + 1));

    for (int k = 0; k < ALP; k++) {
        vector<int> pos;
        for (int i = 0; i < n; i++)
            if (a[i] == k)
                pos.pb(i);
        //dbv(pos);
              
        for (int i = 0; i < sz(pos); i++) {
            int cur = i;
            for (int j = 1; j <= n; j++) {
                for (; cur < sz(pos) && pos[cur] - pos[i] - (cur - i) <= j; cur++);
                opt[k][j] = max(opt[k][j], cur - i);
            }
        }   
    }
    

    //db(opt[0][1]);


    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int len;
        char ch;
        scanf("%d %c", &len, &ch);
        int f = ch - 'a';
        printf("%d\n", min(n, opt[f][len] + len));
    }

    
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}