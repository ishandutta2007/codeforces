#include<iostream>
using namespace std;
int n, p, x, i, nr, maxim, pt;
int main(){
    cin>> n >> p;
    for(i = 1; i <= 30; i++){
        x = n - p * i;
        if(x > 0){
            nr = maxim = 0;
            pt = 0;
            while(x != 0){
                nr += x % 2;
                maxim += (x % 2) * (1 << pt);
                pt++;
                x /= 2;
            }
            if(nr <= i && maxim >= i){
                cout<< i;
                return 0;
            }
        }
    }
    cout<< -1;
}