#include<iostream>
#include<cstring>
using namespace std;
int n, i;
char a[30], b[30], ff[200], s[1005];
int main(){
    cin>> a + 1;
    cin>> b + 1;
    for(i = 1; i <= 26; i++){
        ff[ a[i] ] = b[i];
        ff[ a[i] - 'a' + 'A' ] = b[i] - 'a' + 'A';
    }
    cin>> s + 1;
    n = strlen(s + 1);
    for(i = 1; i <= n; i++){
        if(s[i] >= '0' && s[i] <= '9'){
            cout<< s[i];
        }
        else{
            cout<< ff[ s[i] ];
        }
    }
    return 0;
}