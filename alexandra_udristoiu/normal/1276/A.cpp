#include<iostream>
#include<cstring>
using namespace std;
int t, n, i, nr;
int p[150005];
char s[150005];
int main(){
    cin>> t;
    for(; t; t--){
        cin>> s + 1;
        n = strlen(s + 1);
        nr = 0;
        for(i = 1; i <= n; i++){
            if(i + 2 <= n && s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o'){
                if(i + 4 <= n && s[i + 3] == 'n' && s[i + 4] == 'e'){
                    p[++nr] = i + 2;
                    i += 4;
                }
                else{
                    p[++nr] = i + 1;
                    i += 2;
                }
            }
            else{
                if(i + 2 <= n && s[i] == 'o' && s[i + 1] == 'n' && s[i + 2] == 'e'){
                    p[++nr] = i + 1;
                    i += 2;
                }
            }
        }
        cout<< nr <<"\n";
        for(i = 1; i <= nr; i++){
            cout<< p[i] <<" ";
        }
        cout<<"\n";
    }
}