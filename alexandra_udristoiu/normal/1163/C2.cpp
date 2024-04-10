#include<iostream>
#include<algorithm>
#define x first
#define y second
using namespace std;
int n, nr, i, j, nr2, x;
long long sol;
pair<int, int> v[1005];
struct str{
    int a, b, c;
    double r;
};
str w[1000005];
int cmp(str d, str e){
    if(d.a != e.a){
        return d.a < e.a;
    }
    if(d.b != e.b){
        return d.b < e.b;
    }
    return d.c < e.c;
}
int cmp2(str d, str e){
    return d.r < e.r;
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
    for(i = 1; i <= nr; i++){
        if(w[i].b == 0){
            w[i].r = 1000000;
        }
        else{
            w[i].r = w[i].a * 1.0 / w[i].b;
        }
    }
    sort(w + 1, w + nr + 1, cmp2);
    nr2 = 1;
    for(i = 2; i <= nr; i++){
        if(w[i].r == w[i - 1].r){
            nr2++;
        }
        else{
            sol += nr2 * 1LL * (nr - nr2);
            nr2 = 1;
        }
    }
    sol += nr2 * 1LL * (nr - nr2);
    cout<< sol / 2;
}