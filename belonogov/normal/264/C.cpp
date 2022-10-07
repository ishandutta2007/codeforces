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
const long long inf = 1e16;

struct ball{
    long long v, c;
    ball(){}
    ball(long long _v, long long _c){
        v = _v;
        c = _c;
    }
};

ball e[maxn];
long long c[maxn];
ball r1, r2;
    
void upd(ball a){
    if (a.v > r1.v){
        if (a.c == r1.c){
            r1 = a;
            return;
        }
        r2 = r1;
        r1 = a;        
        return;
    }
    if (a.v > r2.v && a.c != r1.c)
        r2 = a;    
}
    
int main(){
//     freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int n, q;
    long long val, a, b;
    scanf("%d%d", &n, &q);
    for(int i = 0; i < n; i++)
        cin >> e[i].v;
   for(int i = 0; i < n; i++)
        cin >> e[i].c;
   
    for(int tt = 0; tt < q; tt++){
        cin >> a >> b;
        for(int i = 0; i <= n; i++)
            c[i] = -inf;
        r1 = ball(0, n + 1);
        r2 = ball(-inf, -inf);
        for(int i = 0; i < n; i++){
            if (r1.c == e[i].c){
    val = r2.v;
    assert(r2.c != e[i].c);
            }
            else
    val = r1.v;
            assert(val != -inf);
            
            if (c[e[i].c] != -inf && e[i].v * a > 0){
    c[e[i].c] = c[e[i].c] + e[i].v * a;
    upd(ball(c[e[i].c], e[i].c));
            }
            if (c[e[i].c] < val + e[i].v * b){
    c[e[i].c] = val + e[i].v * b;
    upd(ball(c[e[i].c], e[i].c));   
            }
        }
        assert(r1.v >= 0);
        cout << r1.v << endl;
    }
    
    
    
    

    return 0;
}