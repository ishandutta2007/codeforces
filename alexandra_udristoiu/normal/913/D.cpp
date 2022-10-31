#include<cstdio>
#include<algorithm>
#define DIM 200005
using namespace std;
int n, maxim, sum, nr, i, sol, x, u;
int h[DIM];
pair<int, int> w[DIM];
struct str{
    int a, t, ind;
};
str v[DIM];
int cmp(str x, str y){
    return x.a > y.a;
}
void upd(){
    int c = nr, p = c / 2;
    while(p > 0 && h[p] < h[c]){
        swap(h[p], h[c]);
        c = p;
        p = c / 2;
    }
}
void elim(){
    int p = 1, c = 2;
    while(c <= nr){
        if(c + 1 <= nr && h[c + 1] > h[c]){
            c++;
        }
        if(h[p] < h[c]){
            swap(h[p], h[c]);
            p = c;
            c = p + p;
        }
        else{
            break;
        }
    }
}
int main(){
    scanf("%d%d", &n, &maxim);
    for(i = 1; i <= n; i++){
        scanf("%d%d", &v[i].a, &v[i].t);
        v[i].ind = i;
    }
    u = 1;
    sort(v + 1, v + n + 1, cmp);
    for(i = n; i >= 1; i--){
        if(nr > i){
            sum -= h[1];
            swap(h[1], h[nr]);
            nr--;
            elim();
        }
        while(v[u].a == i){
            if(nr < i && sum + v[u].t <= maxim){
                sum += v[u].t;
                h[++nr] = v[u].t;
                upd();
            }
            else{
                if(v[u].t < h[1]){
                    sum -= h[1] - v[u].t;
                    h[1] = v[u].t;
                    elim();
                }
            }
            u++;
        }
        if(sol < nr){
            sol = nr;
            x = i;
        }
    }
    nr = 0;
    printf("%d\n%d\n", sol, sol);
    for(i = 1; i <= n; i++){
        if(v[i].a >= x){
            w[++nr] = make_pair(v[i].t, v[i].ind);
        }
    }
    sort(w + 1, w + nr + 1);
    for(i = 1; i <= sol; i++){
        printf("%d ", w[i].second);
    }
}