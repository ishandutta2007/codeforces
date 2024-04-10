#include<iostream>
#define INF 1000000000
using namespace std;
int n, i, ok1, ok2, minim, maxim, x;
long long sol;
int main(){
    cin>> n;
    if(n == 1){
        cin>> x;
        cout<< x;
        return 0;
    }
    ok1 = ok2 = 1;
    minim = INF;
    maxim = -INF;
    for(i = 1; i <= n; i++){
        cin>> x;
        minim = min(minim, x);
        maxim = max(maxim, x);
        if(x > 0){
            ok2 = 0;
            sol += x;
        }
        else{
            ok1 = 0;
            sol -= x;
        }
    }
    if(ok1 + ok2 == 0){
        cout<< sol;
    }
    else{
        if(ok1 == 1){
            cout<< sol - 2 * minim;
        }
        else{
            cout<< sol + 2 * maxim;
        }
    }
}