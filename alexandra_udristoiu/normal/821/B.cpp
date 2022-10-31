#include<iostream>
using namespace std;
int x, y, m, b, i;
long long sol, sum, s[10000005];
double a;
int main(){
    cin>> m >> b;
    for(i = 1; i <= 10000000; i++){
        s[i] = s[i - 1] + i;
    }
    for(x = 0; ; x++){
        a = -(x * 1.0 / m) + b;
        if(a < 0){
            break;
        }
        y = (int) a;
        sum = s[y] * (x + 1) + s[x] * (y + 1);
        sol = max(sol, sum);
    }
    cout<< sol;
    return 0;
}