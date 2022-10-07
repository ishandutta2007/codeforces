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
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#ifdef DEBUG
    #define epr(...) fprintf(stderr, __VA_ARGS__)
#else
    #define epr ()
#endif 


typedef long long ll;
typedef vector < int > vi;

const int maxn = (int)2e5;
const int inf = (int)1e9;
const int MOD = (1 << 22) - 1;
const int maxH = (1 << 22);


const long long P = 1e9 + 7;
const long long p1 = 59, p2 = 997;

struct event{
    int p, sum, cnt;
    vector < int > a;
    vector < int > b;
    event(){cnt = 0;}
    long long gethash(){
        long long ans = 0;
        for(int i = 0; i < (int)a.size(); i++)
            ans = ans * P + b[i] * p1 + a[i] * p2;
        ans += p;
        return ans;
    }    
};
long double ans = 0;
long long hashT[maxH];
long double value[maxH];

int find(long long hash){
    int i;
    for(i = hash & MOD; hashT[i] != 0 && hashT[i] != hash; i = (i + 1) & MOD);
    
    if (hashT[i] == 0)
        return -1;
    return i;
}

void add(long long hash, long double ans){
    int i;
    for(i = hash & MOD; hashT[i] != 0 && hashT[i] != hash; i = (i + 1) & MOD);
    
    assert(hashT[i] != hash);
    hashT[i] = hash;
    value[i] = ans;
}


long double rec(event a){
    int len = a.a.size();
    long long hash = a.gethash() + 1;
//     epr("\tfind hash %lld\n", hash);
//     for(int i = 0; i < len; i++)
//         epr("%d ", a.a[i]);
//     epr("\n");
//     for(int i = 0; i < len; i++)
//         epr("%d ", a.b[i]);
//     epr("\n");
//     
    
    int pos = find(hash);
    long double ans = 0;
    event b;
    if (a.p < 0)
        return a.cnt - 1;
    if (len == 0)
        return a.cnt;
    if (pos != -1)
        return value[pos];
    for(int i = 0; i < len; i++){
        b = a;
        assert(b.b[i] > 0);
        b.sum--;
        b.p -= b.a[i];
        b.cnt++;
        if (b.b[i] != 1)
            b.b[i]--;
        else{
            b.a.erase(b.a.begin() + i);
            b.b.erase(b.b.begin() + i);        
        }
        ans += rec(b) * (a.b[i] * 1.0 / a.sum);
        
    }
    add(hash, ans);
//     epr("\tadd hash %lld ans %lf\n", hash, (double)ans);
//     epr("\np %d sum %d  cnt %d ans %lf\n", a.p, a.sum, a.cnt, (double)ans);
//     for(int i = 0; i < len; i++)
//         epr("%d ", a.a[i]);
//     epr("\n");
//     for(int i = 0; i < len; i++)
//         epr("%d ", a.b[i]);
//     epr("\n");

 
    return ans;
}

int c[maxn];
vector < int > a;

// void solve2(int n, int p){
//     long double ans2 = 0;
//     int j;
//     for(int i = 0; i < n; i++)
//         c[i] = a[i];
//     int cnt = 10000;
//     for(int t = 0; t < cnt; t++){
//         random_shuffle(c, c + n);
// //         for(int i = 0; i < n; i++)
// //             epr("%d ", c[i]);
// //         epr("\n");
//         int p1 = p;
//         for(j = 0; j < n && p1 >= 0; j++)
//             p1 -= c[j];
//         if (p1 < 0)
//             j--;
// //         epr("p1 %d j %d\n", p1, j);
//         ans2 += j * 1.0 / cnt;
//     }
//     cerr << "ans2 " << fixed  << ans2 << endl;
// }

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int n, p;
    
    srand(time(NULL));
    event start;
    scanf("%d", &n);
    a.resize(n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &p);
    
//     solve2(n, p);
    
   
    sort(a.begin(), a.end());
    start.p = p;
    start.sum = n;
    for(int i = 0; i < n; i++){
        if (i == 0 || a[i - 1] != a[i])
            start.a.pb(a[i]), start.b.pb(1);
        else
            start.b[(int)start.b.size() - 1]++;
    }
    
    ans = rec(start);
    cout.precision(20);
    assert(0 <= ans && ans <= n);
    cout << fixed << ans << endl;

    return 0;
}