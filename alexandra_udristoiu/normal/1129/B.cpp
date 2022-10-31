#include<iostream>
using namespace std;
int k, i, p;
long long sum, sum1, sum2;
int v[2005];
int main(){
    cin>> k;
    for(i = 998; i <= 2000; i++){
        v[i] = 100000;
        sum += v[i];
    }
    p = 998;
    while( (sum * 997 - k) % 2000 != 0){
        v[p]--;
        sum--;
        if(v[p] == 1){
            p++;
        }
    }
    sum = sum * 997 - k;
    sum /= 2000;
    for(i = 997; i >= 1; i--){
        v[i] = -min(sum, 100000LL);
        sum += v[i];
    }
    cout<<"2000\n";
    for(i = 1; i <= 2000; i++){
        cout<< v[i] <<" ";
    }
  /*  for(i = 998; i <= 2000; i++){
        sum1 += v[i];
        sum2 += v[i];
    }
    for(i = 997; i >= 1; i--){
        sum2 += v[i];
    }
    cout<< sum2 * 2000 - sum1 * 1003;*/
}