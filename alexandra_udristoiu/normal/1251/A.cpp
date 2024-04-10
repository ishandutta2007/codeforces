#include<iostream>
#include<cstring>
using namespace std;
int n, t, i, nr;
char s[505], ff[130];
int main(){
    cin>> t;
    for(; t; t--){
        cin>> s + 1;
        n = strlen(s + 1);
        nr = 1;
        for(i = 2; i <= n + 1; i++){
            if(s[i] != s[i - 1]){
                if(nr % 2 == 1){
                    ff[ s[i - 1] ] = t;
                }
                nr = 1;
            }
            else{
                nr++;
            }
        }
        for(i = 'a'; i <= 'z'; i++){
            if(ff[i] == t){
                cout<< (char) i;
            }
        }
        cout<<"\n";
    }
}