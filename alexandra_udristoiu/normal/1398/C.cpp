#include<iostream>
#include<cstring>
#define INF 1000005
using namespace std;
int n, t, i, sum;
long long sol;
char s[100005];
int ff[2 * INF + 5];
int main(){
    cin>> t;
    for(; t; t--){
        cin>> n;
        cin>> s + 1;
        for(i = INF - 10 * n; i <= INF + 10 * n; i++){
            ff[i] = 0;
        }
        sol = 0;
        ff[INF] = 1;
        sum = 0;
        for(i = 1; i <= n; i++){
            sum += s[i] - '0' - 1;
            sol += ff[ sum + INF ];
            ff[ sum + INF ]++;
        }
        cout<< sol <<"\n";
    }
}