#include<iostream>
using namespace std;
int m, i, x, p, j, nr, t;
long long n, sum;
int ff[65];
int main(){
    cin>> t;
    for(; t; t--){
        for(i = 0; i <= 60; i++){
            ff[i] = 0;
        }
        cin>> n >> m;
        sum = 0;
        for(i = 1; i <= m; i++){
            cin>> x;
            sum += x;
            p = 0;
            while(x != 0){
                p++;
                x /= 2;
            }
            ff[p]++;
        }
        if(sum < n){
            cout<<"-1\n";
            continue;
        }
        nr = 0;
        for(i = 1; i <= 60; i++){
            if(n % 2 == 0){
                n /= 2;
                ff[i + 1] += ff[i] / 2;
                continue;
            }
            if(ff[i] != 0){
                ff[i]--;
            }
            else{
                for(j = i + 1; j <= 60; j++){
                    if(ff[j] != 0){
                        ff[j]--;
                        break;
                    }
                }
                nr += j - i;
                for(j = j - 1; j >= i; j--){
                    ff[j]++;
                }
            }
            ff[i + 1] += ff[i] / 2;
            n /= 2;
        }
        cout<< nr <<"\n";
    }
}