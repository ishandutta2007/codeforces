#include<iostream>
#define DIM 1000005
using namespace std;
int n, i, j, x, m, y, a, b;
long long sum, sol, s[2 * DIM];
int c[2 * DIM], nr[2 * DIM];
int main(){
    cin>> n >> x >> y;
    for(i = 1; i <= n; i++){
        cin>> a;
        m = max(m, a);
        s[a] += a;
        nr[a]++;
    }
    b = x / y;
    for(i = 2; i <= 2 * m; i++){
        s[i] += s[i - 1];
        nr[i] += nr[i - 1];
    }
    sol = 1000000000000000LL;
    for(i = 2; i <= 2 * m; i++){
        if(c[i] == 1){
            continue;
        }
        sum = 0;
        for(j = i; j <= 2 * m; j += i){
            c[j] = 1;
            if(b >= i - 1){
                sum += ( (nr[j] - nr[j - i]) * 1LL * j - (s[j] - s[j - i]) ) * y;
            }
            else{
                sum += ( (nr[j] - nr[j - b - 1]) * 1LL * j - (s[j] - s[j - b - 1]) ) * y;
                sum += (nr[j - b - 1] - nr[j - i]) * 1LL * x;
            }
        }
        sol = min(sol, sum);
    }
    cout<< sol;
    return 0;
}