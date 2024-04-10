#include<iostream>
#define f first
#define s second
using namespace std;
int n, i, nr, j, ok;
int w[50];
pair<int, int> v[150005];
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> v[i].f >> v[i].s;
    }
    for(i = 2; i * 1LL * i <= max(v[1].f, v[1].s); i++){
        if(v[1].f % i == 0 || v[1].s % i == 0){
            w[++nr] = i;
            while(v[1].f % i == 0){
                v[1].f /= i;
            }
            while(v[1].s % i == 0){
                v[1].s /= i;
            }
        }
    }
    if(v[1].f != 1){
        w[++nr] = v[1].f;
    }
    if(v[1].s != 1){
        w[++nr] = v[1].s;
    }
    for(i = 1; i <= nr; i++){
        ok = 1;
        for(j = 2; j <= n; j++){
            if(v[j].f % w[i] != 0 && v[j].s % w[i] != 0){
                ok = 0;
            }
        }
        if(ok == 1){
            break;
        }
    }
    if(i == nr + 1){
        cout<< -1;
    }
    else{
        cout<< w[i];
    }
}