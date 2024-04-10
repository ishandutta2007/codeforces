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

const int maxn = 300;
const int inf = (int)1e9;
const int X = 1e6;
const int step = 1e3;

struct pnt{
    int x, y;
    pnt(){}
    pnt(int x, int y): x(x), y(y){};
    pnt operator + (pnt A){
        return pnt(x + A.x, y + A.y);
    }
    pnt operator - (pnt A){
        return pnt(x - A.x, y - A.y);
    }
    long long operator * (pnt A){
        return x * 1ll * A.y - y * 1ll * A.x;
    }
    pnt operator * (int k){
        return pnt(x * k, y * k);
    }
    
    void print(){
        printf("%d %d\n", x, y);
    }
    void Epr(){
        epr("%d %d\n", x, y);
    }
};

pnt a[maxn];
pnt b[maxn];

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int n, m, cur = 0;
    pnt p, d;
    cin >> n >> m;
    if ((n == 6 || n == 5) && m == 3){
        cout << -1 << endl;
        return 0;
    }
    a[0] = pnt(X - 1, -1);
    b[0] = pnt(X + X - 1, -2);
    
    a[1] = pnt(-1, -X + 1);
    b[1] = pnt(-2, -X + 1 - X);
    
    a[2] = pnt(- X, 1);
    b[2] = pnt(- X - X, 2);
    
    a[3] = pnt(1, X);
    b[3] = pnt(2, X + X);
    
    cur = 4;
    p = a[3];
    for(int i = 1; cur < m; cur++, i++){
        d = pnt(step, -i);
        p = p + d;
        a[cur] = p;
    } 
    
    for(int i = 4; i < m; i++)
        b[i] = a[i] * 2;
    
    for(int i = m; i < n; i++)
        b[i] = a[i - m];
    
    
    
    
    for(int i = 0; i < n; i++)
        b[i].print();
    
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            for(int k = j + 1; k < n; k++)
    if ((b[j] - b[i]) * (b[k] - b[i]) == 0){
        b[i].Epr();
        b[j].Epr();
        b[k].Epr();
        assert(false);
    }
        
    
    


    return 0;
}