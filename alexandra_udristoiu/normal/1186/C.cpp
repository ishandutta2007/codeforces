#include<iostream>
#include<cstring>
#define DIM 1000005
using namespace std;
int n, m, i, sol, sum;
int s[DIM];
char a[DIM], b[DIM];
int main(){
    cin>> a + 1;
    n = strlen(a + 1);
    cin>> b + 1;
    m = strlen(b + 1);
    for(i = 2; i <= n; i++){
        s[i] = s[i - 1];
        if(a[i] != a[i - 1]){
            s[i]++;
        }
    }
    for(i = 1; i <= m; i++){
        if(a[i] != b[i]){
            sum++;
        }
    }
    if(sum % 2 == 0){
        sol++;
    }
    for(i = 2; i + m - 1 <= n; i++){
        sum += s[i + m - 1] - s[i - 1];
        if(sum % 2 == 0){
            sol++;
        }
    }
    cout<< sol;
}