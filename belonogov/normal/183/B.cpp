#include <iostream>
#include <cstdio>

using namespace std;
#define forn(i, n) for(i = 0; i < n; i++)
#define forab(i, a, b) for(i = a; i < b; i++)
#define forba(i, b, a) for(i = b; i > a; i--)

typedef long long ll;
typedef long double ld;
const ld eps = 1e-11;

struct pnt{
    ll x, y;
    pnt(){}
    pnt(ll _x, ll _y){
        x = _x;
        y = _y;
    }


};
struct line{
    ll a, b, c;


};

pnt p[300];
ll ans[1000 * 1000 + 2];

line getline(pnt p1, pnt p2){
    line l;
    l.a = p1.y - p2.y;
    l.b = p2.x - p1.x;
    l.c = - p1.x * (l.a) - p1.y * (l.b);
    return l;
}

pnt per(line l1, line l2){
    ld x;
    ld y;
    y = (l1.a * l2.c - l1.c * l2.a) * 1.0 / (l1.b * l2.a - l1.a * l2.b);
    x = (l2.c * l1.b - l2.b * l1.c) * 1.0 / (l1.a * l2.b - l2.a * l1.b);
    if (abs(y) > eps || (x - (long long)x) > eps) 
        y = 1;
    return pnt((long long) x, (long long) y); 
}


int main(){
    int i, j, k, n, m;
    ll res;
    pnt p1;
    line l, l0;
    cin >> n >> m;
    forn(i, m)
        cin >> p[i].x >> p[i].y;

    forab(i, 1, n + 1)
        ans[i] = 1;


    l0 = getline(pnt(0, 0), pnt(1, 0));
    forn(i, m)
        forn(j, m)
            if (i != j){
                l = getline(p[i], p[j]);
                p1 = per(l0, l);
                if (p1.y == 0 && p1.x >= 1 && p1.x <= n){ 
                    res = 0;
                    forn(k, m)
                        if (l.a * p[k].x + l.b * p[k].y + l.c == 0)
                            res++;
                    ans[p1.x] = max(ans[p1.x], res);
                }
            }
    res = 0;
    forab(i, 1, n + 1)
        res += ans[i];
    cout << res;

    return 0;

}