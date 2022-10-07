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

const int maxn = 110;
const int maxm = 2e5;
const long long inf = 1e15;
const long double eps = 1e-9;
const long double pi = acos(0) * 2;

struct pnt{
    long double x, y;
    pnt(){}
    pnt(long double x, long double y): x(x), y(y){};
    
    pnt operator + (pnt a){
        return pnt(x + a.x, y + a.y);
    }
    pnt operator - (pnt a){
        return pnt(x - a.x, y - a.y);
    }
    pnt operator / (long double k){
        return pnt(x / k, y / k);
    }    
    pnt turn(){
        return pnt(-y, x);
    }
    long double operator * (pnt a){
        return x * a.y - y * a.x;
    }
    long double operator % (pnt a){
        return x * a.x + y * a.y;
    }
    long double len2(){
        return x * x + y * y;
    }
    long double len(){
        return sqrt(x * x + y * y);
    }
    void read(){
        cin >> x >> y;
    }
    void Epr(){
        cerr << x << " " << y << endl;
    }
};

struct line{
    long double a, b, c;
    line(){}
    line(pnt p1, pnt p2){
        a = p1.y - p2.y;
        b = - (p1.x - p2.x);
        c = - a * p1.x - b * p1.y;
    }
    pnt operator * (line l){
        return pnt((l.c * b - c * l.b) / (a * l.b - l.a * b),
        (l.c * a - c * l.a) / (b * l.a - l.b * a));
    }
    
};


pnt a[maxn];
pnt b[maxm];
pair < long double, pnt > c[maxn];
int m;

void getP(pnt A, pnt B, pnt C){
    pnt C1, B1, D, E, G, v;
    line l1, l2;
    C1 = (A + B) / 2;
    v = (A - B).turn();
    D = C1 + v;
    l1 = line(D, C1);
    
    B1 = (A + C) / 2;
    v = (C - A).turn();
    E = B1 + v;
    l2 = line(E, B1);
    
    G = l1 * l2;
    b[m++] = G;
}

bool cmp(pair < long double, pnt > a, pair < long double, pnt > b){
    return a.ff < b.ff;
}

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
    int n, cur;
    long double ans, dist;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        a[i].read();
    
    
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            for(int k = j + 1; k < n; k++)
    if (abs((a[i] - a[j]) * (a[i] - a[k])) > eps)
       getP(a[i], a[j], a[k]);
            
    ans = -1;
//     epr("m %d\n", m);
    for(int i = 0; i < m; i++){
        cur = 0;
        dist = inf;
        for(int j = 0; j < n; j++){
            if ((a[j] - b[i]).len() < dist - eps){
    cur = 0;
    dist = (a[j] - b[i]).len();
            }
            if (abs((a[j] - b[i]).len() - dist) < eps)
    c[cur++].ss = a[j] - b[i];
        } 
//         epr("cur %d\n", cur);
          
        if (cur >= 3){
            bool flag = 1;
            for(int j = 0; j < cur; j++)
    c[j].ff = atan2(pnt(1, 0) * c[j].ss, pnt(1, 0) % c[j].ss);
           sort(c, c + cur, cmp);
            /*
            epr("\n\n");
            b[i].Epr();
            for(int j = 0; j < cur; j++)
    epr("%lf ", (double)(c[j].ff / pi * 180));
            epr("\n\n");
            
            for(int j = 0; j < cur; j++)
    c[j].ss.Epr();
            epr("\n\n");
            */
            for(int j = 0; j < cur; j++)
    if (c[j].ss * c[(j + 1) % cur].ss  <= eps)
        flag = 0;
    
/*//    
            if (c[0].ff - (c[cur - 1].ff - pi * 2) > pi)
    flag = 0;*/
//             epr("flag %d\n", flag);
            if (flag) ans = max(ans, dist);
        }
    }
    cout.precision(15);
    if (ans == -1)
        printf("-1\n");
    else
        cout << fixed << ans << endl;
         
    return 0;
}

/*  
//     epr("uk %d\n", uk);
    if (uk == 0){
        cout << "-1\n";
        return 0;
    }
//     for(int i = 0; i < uk; i++)
//         b[i].Epr();
    long double ans = 0, res;
    for(int i = 0; i < uk; i++){
        res = inf;
        for(int j = 0; j < n && res > ans; j++)
            res = min(res, (b[i] - a[j]).len2());
        ans = max(res, ans);
    }
    cout.precision(15);
    cout << fixed << sqrt(ans) << endl;
   */