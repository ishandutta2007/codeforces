#include <bits/stdc++.h>
using namespace std;
static char sym[] = {'A','H','I','M','O','T','U','V','W','X','Y','o','v','w','x'};
static char sym2[2][2] = {{'b','d'}, {'p','q'}};
bool f(char c){
    for(char x:sym){
        if(c == x){
            return true;
        }
    }
    return false;
}
int main(){

    string s;
    cin >> s;
    int n = s.length();
    for(int i = 0; i<n/2; i++){
        char c = s[i];
        char d = s[n-i-1];
        if(!((c == d && f(c))|| (c == 'p' && d == 'q') || (c=='q' &&d == 'p')||(c == 'b' && d == 'd') || (c == 'd' &&d == 'b'))){
            cout<< "NIE";
            return 0;
        }
    }
    if(n%2 == 1){
        if(!(f(s[(n-1)/2]))){
            cout<< "NIE";
            return 0;
        }
    }
    cout<< "TAK";
}