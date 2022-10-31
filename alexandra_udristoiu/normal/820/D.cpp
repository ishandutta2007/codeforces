#include<cstdio>
#include<iostream>
#define DIM 1000005
using namespace std;
int n, i, p, poz, nr1, nr2;
int v[DIM], w[DIM];
long long sol, sum;
int main(){
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        scanf("%d", &v[i]);
        if(v[i] >= i){
            nr1++;
            sum += v[i] - i;
            w[ v[i] - i ]++;
        }
        else{
            nr2++;
            sum += i - v[i];
            w[ n + v[i] - i ]++;
        }
    }
    sol = sum;
    poz = 0;
    for(i = 1; i < n; i++){
        nr1 -= w[i - 1];
        nr2 += w[i - 1];
        nr2--;
        sum = sum - nr1 + nr2 - (n - v[n - i + 1]) + (v[n - i + 1] - 1);
        nr1++;
        if(sum < sol){
            sol = sum;
            poz = i;
        }
    }
    cout<< sol <<" "<< poz;
    return 0;
}