#include<iostream>
#define DIM 200005
using namespace std;
int n, i, m, sum, nr1, nr2, x, j;
long long sol;
int c[DIM], pt[DIM], num[DIM];
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> x;
        num[x]++;
        m = max(m, x);
    }
    sol = 1;
    for(i = 2; i <= m; i++){
        if(c[i] == 0){
            sum = 0;
            nr1 = nr2 = m;
            for(j = i; j <= m; j += i){
                if(j != i){
                    c[j] = 1;
                }
                if( (j / i) % i == 0){
                    pt[j] = 1 + pt[j / i];
                }
                else{
                    pt[j] = 1;
                }
                sum += num[j];
                if(pt[j] < nr1 && num[j] > 0){
                    nr2 = nr1;
                    nr1 = pt[j];
                    if(num[j] > 1){
                        nr2 = min(nr2, pt[j]);
                    }
                }
                else{
                    if(pt[j] < nr2 && num[j] > 0){
                        nr2 = pt[j];
                    }
                }
            }
            if(sum < n){
                nr2 = nr1;
                nr1 = 0;
            }
            if(sum < n - 1){
                nr1 = nr2 = 0;
            }
            for(j = 1; j <= nr2; j++){
                sol *= i;
            }
        }
    }
    cout<< sol;
}