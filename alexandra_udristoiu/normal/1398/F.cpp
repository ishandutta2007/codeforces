#include<iostream>
#define DIM 1000005
using namespace std;
int n, i, p, u, nr, p0, p1, k, aux;
char s[DIM];
int nxt[DIM], d[DIM];
int main(){
    cin>> n;
    cin>> s + 1;
    p0 = p1 = d[n + 1] = n + 1;
    for(i = n; i >= 1; i--){
        if(s[i] == '?'){
            d[i] = d[i + 1];
        }
        else{
            if(s[i] == '0'){
                d[i] = p1;
                p0 = i;
            }
            else{
                d[i] = p0;
                p1 = i;
            }
        }
    }
    for(i = 1; i <= n; i++){
        nxt[i] = i + 1;
    }
    for(k = 1; k <= n; k++){
        nr = 0;
        p = 1;
        while(p <= n){
            if(d[p] - p >= k){
                p += k;
                nr++;
                continue;
            }
            u = p;
            while(u <= n && d[u] - u < k){
                u = nxt[u];
            }
            while(p != u){
                aux = nxt[p];
                nxt[p] = u;
                p = aux;
            }
        }
        cout<< nr <<" ";
    }
}