#include<iostream>
using namespace std;
int n, x, y, nr, i;
char s[300005];
int main(){
    cin>> n >> x >> y;
    cin>> s + 1;
    for(i = 1; i <= n; i++){
        if(s[i] != s[i - 1] && s[i] == '0'){
            nr++;
        }
    }
    if(nr == 0){
        cout<< 0;
    }
    else{
        cout<< min(nr * 1LL * y, (nr - 1) * 1LL * x + y);
    }
}