#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int n, a, b, i, nr;
long long sol, d[1000005];
int v[1000005], p[65];
void getprim(int x){
    int aux = x, i;
    for(i = 2; i * i <= x; i++){
        if(aux % i == 0){
            p[++nr] = i;
            while(aux % i == 0){
                aux /= i;
            }
        }
    }
    if(aux != 1){
        p[++nr] = aux;
    }
}
long long verif(int p){
    int u1, u2, y, x = 0, i;
    long long sol1, sol2;
    u1 = n;
    for(i = 1; i <= n; i++){
        if(v[i] % p != 0 && (v[i] - 1) % p != 0 && (v[i] + 1) % p != 0){
            u1 = i - 1;
            break;
        }
        else{
            x++;
        }
    }
    sol1 = u1 * 1LL * a;
    y = 0;
    for(i = 1; i <= u1; i++){
        if(v[i] % p != 0){
            y++;
        }
        sol1 = min(sol1, (u1 - i) * 1LL * a + y * 1LL * b);
        d[i] = y * 1LL * b;
    }
    if(u1 == n){
        sol2 = a;
        for(i = 1; i <= n; i++){
            d[i] = min(d[i], sol2);
            sol2 = min(d[i], sol2) + a;
        }
        sol2 = 10000000000000000LL;
        y = 0;
        for(i = n; i >= 1; i--){
            if(v[i] % p != 0){
                y++;
            }
            sol2 = min(sol2, d[i - 1] + y * 1LL * b);
        }
        return min(sol2, sol1);
    }
    for(i = n; i >= 1; i--){
        if(v[i] % p != 0 && (v[i] - 1) % p != 0 && (v[i] + 1) % p != 0){
            u2 = i + 1;
            break;
        }
        else{
            x++;
        }
    }
    sol2 = (n - u2 + 1) * 1LL * a;
    y = 0;
    for(i = n; i >= u2; i--){
        if(v[i] % p != 0){
            y++;
        }
        sol2 = min(sol2, (i - u2) * 1LL * a + y * 1LL * b);
    }
    return sol1 + sol2 + a * 1LL * (n - x);
}
int main(){
    scanf("%d%d%d", &n, &a, &b);
    for(i = 1; i <= n; i++){
        scanf("%d", &v[i]);
    }
    getprim(v[1]);
    getprim(v[1] - 1);
    getprim(v[1] + 1);
    getprim(v[n]);
    getprim(v[n] - 1);
    getprim(v[n] + 1);
    sol = 10000000000000000LL;
    sort(p + 1, p + nr + 1);
    for(i = 1; i <= nr; i++){
        if(p[i] != p[i - 1]){
            sol = min(sol, verif(p[i]) );
        }
    }
    cout<< sol;
}