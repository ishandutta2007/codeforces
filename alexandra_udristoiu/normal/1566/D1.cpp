#include<iostream>
#include<algorithm>
using namespace std;
int t, n, i, sol, j, m;
int v[305];
int main(){
    cin>> t;
    for (; t; t--) {
        cin>> m >> n;
        for (i = 1; i <= n; i++) {
            cin>> v[i];
        }
        sol = 0;
        for (i = 2; i <= n; i++) {
            for (j = 1; j < i; j++) {
                if (v[j] < v[i]) {
                    sol++;
                }
            }
        }
        cout<< sol <<"\n";
    }
}