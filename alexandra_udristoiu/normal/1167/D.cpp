#include<iostream>
#define DIM 200005
using namespace std;
int n, i, u;
char s[DIM], sol[DIM];
int c[DIM];
int main(){
    cin>> n;
    cin>> s + 1;
    for(i = 1; i <= n; i++){
        if(s[i] == '('){
            c[++u] = i;
            sol[i] = '0' + u % 2;
        }
        else{
            sol[i] = sol[ c[u] ];
            u--;
        }
    }
    cout<< sol + 1;
}