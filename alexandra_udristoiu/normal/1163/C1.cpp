#include<iostream>
#include<algorithm>
#define x first
#define y second
using namespace std;
int n, nr, i, j, sol, nr2, x;
pair<int, int> v[55];
struct str{
    int a, b, c;
};
str w[2505];
int cmp(str d, str e){
    if(d.a != e.a){
        return d.a < e.a;
    }
    if(d.b != e.b){
        return d.b < e.b;
    }
    return d.c < e.c;
}
int cmmdc(int a, int b){
    int r;
    while(b != 0){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> v[i].x >> v[i].y;
    }
    for(i = 2; i <= n; i++){
        for(j = 1; j < i; j++){
            nr++;
            w[nr].a = v[j].y - v[i].y;
            w[nr].b = v[i].x - v[j].x;
            if(w[nr].a == 0){
                w[nr].b = 1;
            }
            else{
                if(w[nr].b == 0){
                    w[nr].a = 1;
                }
                else{
                    x = cmmdc(w[nr].a, w[nr].b);
                    w[nr].a /= x;
                    w[nr].b /= x;
                }
            }
            w[nr].c = -w[nr].a * v[i].x - w[nr].b * v[i].y;
        }
    }
    sort(w + 1, w + nr + 1, cmp);
    nr2 = 1;
    for(i = 2; i <= nr; i++){
        if(w[i].a != w[nr2].a || w[i].b != w[nr2].b || w[i].c != w[nr2].c){
            w[++nr2] = w[i];
        }
    }
    nr = nr2;
    for(i = 1; i < nr; i++){
        for(j = i + 1; j <= nr; j++){
            if(w[i].a * 1LL * w[j].b != w[i].b * 1LL * w[j].a){
                sol++;
            }
        }
    }
    cout<< sol;
}