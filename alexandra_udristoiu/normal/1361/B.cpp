#include<iostream>
#include<cstdio>
#include<algorithm>
#define f first
#define s second
#define DIM 1000005
#define mod 1000000007
#define INF 1e12
using namespace std;
int t, n, p, i, sol, x, k, j, u;
int w[DIM];
long long re;
pair<int, int> v[DIM];
int mult(int x, int e){
    if(e == 0){
        return 1;
    }
    else{
        int a = mult(x, e / 2);
        if(e % 2 == 0){
            return a * 1LL * a % mod;
        }
        else{
            return a * 1LL * a % mod * x % mod;
        }
    }
}
int main(){
    cin>> t;
    for(; t; t--){
        scanf("%d%d", &n, &p);
        for(i = 1; i <= n; i++){
            scanf("%d", &w[i]);
        }
        if(p == 1){
            printf("%d\n", n % 2);
            continue;
        }
        sol = 0;
        sort(w + 1, w + n + 1);
        k = 1;
        v[1] = make_pair(w[1], 1);
        for(i = 2; i <= n; i++){
            if(w[i] == v[k].f){
                v[k].s++;
            }
            else{
                v[++k] = make_pair(w[i], 1);
            }
        }
        for(i = k; i >= 1; i--){
            if(v[i].s % 2 == 1){
                re = 1;
                u = i - 1;
                for(j = v[i].f - 1; j >= 0; j--){
                    re *= p;
                    if(re > DIM){
                        break;
                    }
                    if(v[u].f == j){
                        re -= v[u].s;
                        if(re <= 0){
                            break;
                        }
                        u--;
                    }
                }
                if(re <= 0){
                    re = 1;
                    u = i - 1;
                    for(j = v[i].f - 1; j >= 0; j--){
                        re *= p;
                        if(re > DIM){
                            break;
                        }
                        if(v[u].f == j){
                            if(re <= v[u].s){
                                v[u].s -= re;
                                break;
                            }
                            else{
                                re -= v[u].s;
                                v[u].s = 0;
                            }
                            u--;
                        }
                    }
                }
                else{
                    sol = mult(p, v[i].f);
                    for(j = i - 1; j >= 1; j--){
                        sol -= v[j].s * 1LL * mult(p, v[j].f) % mod;
                        if(sol < 0){
                            sol += mod;
                        }
                    }
                    break;
                }
            }
        }
        printf("%d\n", sol);
    }
}