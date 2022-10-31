#include<iostream>
#include<cstring>
using namespace std;
int n, i;
char s[105];
int verif(char c){
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y'){
        return 1;
    }
    return 0;
}
int main(){
    cin>> n;
    cin>> s + 1;
    cout<< s[1];
    for(i = 2; i <= n; i++){
        if(verif(s[i]) == 0){
            cout<< s[i];
        }
        else{
            if(verif(s[i - 1]) == 0){
                cout<< s[i];
            }
        }
    }
}