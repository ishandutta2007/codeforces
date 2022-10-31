#include<iostream>
#include<cstdio>
#define DIM 600005
#define f first
#define s second
using namespace std;
int n, k, m, i, j, sol, r1, r2, x;
int r[DIM], sum[DIM], incl[DIM], ok[DIM];
pair<int, int> p[DIM];
char st[DIM];
int rad(int x){
    while(r[x] > 0){
        x = r[x];
    }
    return x;
}
void uneste(int x, int y){
    int r1, r2;
    r1 = rad(x);
    r2 = rad(y);
    if(incl[r1] == 1){
        sol -= sum[r1];
        incl[r1] = 0;
    }
    if(incl[r2] == 1){
        sol -= sum[r2];
        incl[r2] = 0;
    }
    if(r1 != r2){
        if(r[r1] > r[r2]){
            swap(r1, r2);
        }
        ok[r1] &= ok[r2];
        sum[r1] += sum[r2];
        r[r1] += r[r2];
        r[r2] = r1;
    }
}
int main(){
    cin>> n >> k;
    cin>> st + 1;
    for(i = 1; i <= k; i++){
        scanf("%d", &m);
        for(j = 1; j <= m; j++){
            scanf("%d", &x);
            if(p[x].f == 0){
                p[x].f = i;
            }
            else{
                p[x].s = i;
            }
        }
    }
    for(i = 1; i <= k; i++){
        r[2 * i - 1] = r[2 * i] = -1;
        ok[2 * i - 1] = ok[2 * i] = 1;
        sum[2 * i] = 1;
        incl[2 * i - 1] = 1;
    }
    for(i = 1; i <= n; i++){
        if(p[i].f != 0 && p[i].s == 0){
            r1 = rad(2 * p[i].f - 1);
            r2 = rad(2 * p[i].f);
            if(st[i] == '1'){
                ok[r2] = 0;
                if(incl[r2]){
                    sol += sum[r1] - sum[r2];
                    incl[r1] = 1;
                    incl[r2] = 0;
                }
            }
            else{
                ok[r1] = 0;
                if(incl[r1]){
                    sol += sum[r2] - sum[r1];
                    incl[r1] = 0;
                    incl[r2] = 1;
                }
            }
        }
        if(p[i].s != 0){
            if(st[i] == '1'){
                uneste(2 * p[i].f, 2 * p[i].s);
                uneste(2 * p[i].f - 1, 2 * p[i].s - 1);
            }
            else{
                uneste(2 * p[i].f - 1, 2 * p[i].s);
                uneste(2 * p[i].f, 2 * p[i].s - 1);
            }
            r1 = rad(2 * p[i].f - 1);
            r2 = rad(2 * p[i].f);
            if(ok[r1] == 0){
                sol += sum[r2];
                incl[r2] = 1;
            }
            else{
                if(ok[r2] == 0){
                    sol += sum[r1];
                    incl[r1] = 1;
                }
                else{
                    if(sum[r1] < sum[r2]){
                        sol += sum[r1];
                        incl[r1] = 1;
                    }
                    else{
                        sol += sum[r2];
                        incl[r2] = 1;
                    }
                }
            }
        }
        printf("%d\n", sol);
    }
}