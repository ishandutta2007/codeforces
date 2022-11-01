#include<iostream>
#include<cstring>
using namespace std;
int n, i;
char s[110];
int main(){
    cin>> s + 1;
    n = strlen(s + 1);
    for(i = 2; i < n; i++){
        if(s[i] != s[i - 1] && s[i] != s[i + 1] && s[i - 1] != s[i + 1] && s[i] != '.' && s[i - 1] != '.' && s[i + 1] != '.'){
            cout<<"Yes";
            return 0;
        }
    }
    cout<<"No";
}