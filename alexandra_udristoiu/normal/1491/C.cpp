#include<iostream>
#include<cstring>
using namespace std;
int t, n, i, j;
long long sol;
int s[5005], v[5005];
int main(){
    cin>> t;
    for(; t; t--){
        sol = 0;
        memset(v, 0, sizeof(v) );
        cin>> n;
        for(i = 1; i <= n; i++){
            cin>> s[i];
        }
        for(i = 1; i <= n; i++){
            if(v[i] < s[i] - 1){
                sol += s[i] - v[i] - 1;
                v[i] = s[i] - 1;
            }
            for(j = i + 2; j <= min(n, i + s[i]); j++){
                v[j]++;
            }
            if(v[i] >= s[i]){
                v[i + 1] += v[i] - s[i] + 1;
            }
        }
        cout<< sol <<"\n";
    }
}