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
#include <queue>

using namespace std;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#ifdef DEBUG
    #define epr(...) fprintf(stderr, __VA_ARGS__)
#else
    #define epr 
#endif 


typedef long long ll;
typedef vector < int > vi;

const int maxn = 2e5 + 100;
const int inf = (int)1e9;

struct pnt{
    int x, y;
    pnt(){}
    pnt(int _x, int _y){
        x = _x;
        y = _y;
    }
};

vector < pnt > a;

long long fac(int k, int d, long long m){
    long long ans = 1;
    int x;
    for(int i = 1; i <= k; i++){
        for(x = i; x % 2 == 0 && d > 0; d--, x /= 2);
        ans = (ans * x) % m;
    }
    return ans;
}

bool cmp(pnt a, pnt b){
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int n, cnt, cnt2, x;
    long long ans = 1, m;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        a.pb(pnt(x, i));    
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        a.pb(pnt(x, i));    
    }
    cin >> m;
    
    sort(a.begin(), a.end(), cmp);
    cnt = 1;
    cnt2 = 0;
    for(int i = 1; i < (int)a.size(); i++){
        if (a[i - 1].x == a[i].x){
            if (a[i - 1].y == a[i].y)
    cnt2++;
            cnt++;
        }
        else{
//             epr("cnt %d cnt2 %d\n", cnt, cnt2);
            ans = (ans * fac(cnt, cnt2, m)) % m;
            cnt = 1;
            cnt2 = 0;
        }
    }
    ans = (ans * fac(cnt, cnt2, m)) % m;
     
    
    cout << ans << endl;
    
    return 0;
}