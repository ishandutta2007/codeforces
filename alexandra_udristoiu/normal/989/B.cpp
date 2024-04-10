#include<iostream>
using namespace std;
int n, k, i, ok;
char s[2005];
int main(){
    cin>> n >> k;
    cin>> s + 1;
    for(i = k + 1; i <= n; i++){
        if(s[i] == '.' && s[i - k] == '.'){
            ok = 1;
            s[i] = '0';
            s[i - k] = '1';
        }
        else{
            if(s[i] != s[i - k]){
                ok = 1;
                if(s[i] == '.'){
                    s[i] = '1' - s[i - k] + '0';
                }
                if(s[i - k] == '.'){
                    s[i - k] = '1' - s[i] + '0';
                }
            }
        }
        if(ok == 1){
            for(i = 1; i <= n; i++){
                if(s[i] == '.'){
                    s[i] = '0';
                }
            }
            cout<< s + 1;
            return 0;
        }
    }
    cout<<"No";
}