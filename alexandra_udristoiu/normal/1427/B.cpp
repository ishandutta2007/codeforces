#include<iostream>
#include<algorithm>
#define DIM 100005
using namespace std;
int n, nr, i, lst, k, sum, scor, t;
char s[DIM];
int v[DIM];
int main(){
    cin>> t;
    for(; t; t--){
        cin>> n >> k;
        cin>> s + 1;
        lst = 0;
        sum = nr = scor = 0;
        for(i = 1; i <= n; i++){
            if(s[i] == 'W'){
                if(lst != 0 && lst != i - 1){
                    v[++nr] = i - lst - 1;
                }
                sum++;
                lst = i;
                scor += 1 + (s[i - 1] == 'W');
            }
        }
        k = min(k, n - sum);
        if(k == 0){
            cout<< scor <<"\n";
            continue;
        }
        if(sum == 0){
            cout<< (k - 1) * 2 + 1 <<"\n";
            continue;
        }
        else{
            sort(v + 1, v + nr + 1);
            for(i = 1; i <= nr; i++){
                if(v[i] <= k){
                    k -= v[i];
                    scor += v[i] * 2 + 1;
                }
                else{
                    break;
                }
            }
            scor += k * 2;
        }
        cout<< scor <<"\n";
    }
}