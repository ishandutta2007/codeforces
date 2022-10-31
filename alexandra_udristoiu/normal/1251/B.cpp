#include<iostream>
#include<cstring>
using namespace std;
int t, n, m, i, j, nr0, nr1, imp, sol;
char s[55];
int main(){
    cin>> t;
    for(; t; t--){
        cin>> n;
        nr0 = nr1 = imp = 0;
        for(i = 1; i <= n; i++){
            cin>> s + 1;
            m = strlen(s + 1);
            for(j = 1; j <= m; j++){
                if(s[j] == '0'){
                    nr0++;
                }
                else{
                    nr1++;
                }
            }
            imp += m % 2;
        }
        sol = n;
        if(imp == 0 && nr1 % 2 + nr0 % 2 != 0){
            sol--;
        }
        cout<< sol <<"\n";
    }
}