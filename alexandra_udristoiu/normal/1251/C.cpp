#include<iostream>
#include<cstring>
#define DIM 300005
using namespace std;
int t, n, i, j, m[2];
char s[DIM], c[2][DIM];
int main(){
    cin>> t;
    for(; t; t--){
        cin>> s + 1;
        n = strlen(s + 1);
        m[0] = m[1] = 0;
        for(i = 1; i <= n; i++){
            c[ s[i] % 2 ][ ++m[ s[i] % 2] ] = s[i];
        }
        i = j = 1;
        while(i <= m[0] && j <= m[1]){
            if(c[0][i] < c[1][j]){
                cout<< c[0][i];
                i++;
            }
            else{
                cout<< c[1][j];
                j++;
            }
        }
        for(; i <= m[0]; i++){
            cout<< c[0][i];
        }
        for(; j <= m[1]; j++){
            cout<< c[1][j];
        }
        cout<<"\n";
    }
}