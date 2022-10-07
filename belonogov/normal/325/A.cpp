#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <cmath>

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

const int maxn = -1;
const int inf = 1e9;

struct pnt{
    int x, y;
    pnt(){}
    pnt(int x, int y): x(x), y(y){};
};

pnt a[20];
int mn, mx;
int n;

bool checkin(pnt A, pnt B, pnt C){
    return (A.x <= B.x && B.x <= C.x && A.y <= B.y && B.y <= C.y);
}

void check(pnt p){
    bool flag = 0;
    if (checkin(a[mn], p, a[mx])){
        for(int i = 0; i < n; i++){
            if (checkin(a[i * 2], p, a[i * 2 + 1]))
                flag = 1;
        }
        if (! flag){
            cout << "NO\n";
            exit(0);
        }
    }
}


int main(){
 //   freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n;

    for(int i = 0; i < n * 2; i++)
        cin >> a[i].x >> a[i].y;
    for(int i = 0; i < n * 2; i++){
        a[i].x *= 2;
        a[i].y *= 2;
    }


    mn = 0;
    mx = 0;
    for(int i = 0; i < n * 2; i++){
        if (a[i].x < a[mn].x || (a[i].x == a[mn].x && a[i].y < a[mn].y))
            mn = i;
        if (a[i].x > a[mx].x || (a[i].x == a[mx].x && a[i].y > a[mx].y))
            mx = i;
    }
    if (a[mx].x - a[mn].x != a[mx].y - a[mn].y){
        cout << "NO\n";
        return 0;
    }
    for(int i = 0; i < n; i += 2){
        for(int y = a[i * 2].y; y <= a[i * 2 + 1].y; y++){
            check(pnt(a[i * 2].x - 1, y));
            check(pnt(a[i * 2].x + 1, y));
        }
        for(int y = a[i * 2].y; y <= a[i * 2 + 1].y; y++){
            check(pnt(a[i * 2 + 1].x - 1, y));
            check(pnt(a[i * 2 + 1].x + 1, y));
        }
        for(int x = a[i * 2].x; x <= a[i * 2 + 1].x; x++){
            check(pnt(x, a[i * 2].y + 1));
            check(pnt(x, a[i * 2].y - 1));
        }
        for(int x = a[i * 2].x; x <= a[i * 2 + 1].x; x++){
            check(pnt(x, a[i * 2 + 1].y + 1));
            check(pnt(x, a[i * 2 + 1].y - 1));
        }
    }
    printf("YES\n");



    return 0;
}