#include<iostream>
using namespace std;
int n, i, st, dr;
char s[200005];
long long sol;
int main(){
    cin>> n;
    cin>> s + 1;
    st = 1;
    dr = n;
    while(s[st + 1] == s[st]){
        st++;
    }
    while(s[dr] == s[dr - 1]){
        dr--;
    }
    if(s[1] != s[n]){
        sol += st + n - dr + 2;
    }
    else{
        if(st < dr){
            sol += (st + 1) * 1LL * (n - dr + 2);
        }
        else{
            sol += n * 1LL * (n + 1) / 2;
        }
    }
    cout<< sol % 998244353;
}