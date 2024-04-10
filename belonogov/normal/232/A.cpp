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
#define forn(i, n) for(int i = 0; i < n; i++)
#define forab(i, a, b) for(int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int maxn = 1000;

int a[maxn][maxn];

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int cnt, k, x, uk;
    int n = 100;    
    cin >> k;
    forn(i, 100){
        x = i * (i - 1) * (i - 2) / 6;
        if (x >= k){
            cnt = i - 1;
            break;
        }
    }
    assert(cnt != -1);
    forn(i, cnt)
        forn(j, cnt)
            if (i != j) 
    a[i][j] = 1;
    k -= cnt * (cnt - 1) * (cnt - 2) / 6;
    assert(k >= 0);
    uk = cnt;
    while(k > 0){
        assert(uk < n);
        for(int i = 0; i < cnt; i++){
            if (i <= k){
    a[uk][i] = 1;
    a[i][uk] = 1;
    k -= i;
            }
        }
        
        uk++;
    }
    assert(k == 0);
    cout << n << "\n";
    
    forn(i, n){
        forn(j, n)
            cout << a[i][j];
        cout << "\n";
    }
            
       
    
       

    return 0;
}