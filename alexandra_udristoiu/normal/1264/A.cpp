#include<iostream>
using namespace std;
int t, n, i, s, b, g, ok;
int v[400005];
int main(){
    cin>> t;
    for(; t; t--){
        cin>> n;
        for(i = 1; i <= n; i++){
            cin>> v[i];
        }
        g = s = b = 0;
        v[n + 1] = -1;
        ok = 0;
        for(i = 2; i <= n + 1; i++){
            if(v[i] != v[1]){
                g = i - 1;
                break;
            }
        }
        for(i = g + 1; i <= n / 2 + 1; i++){
            if(v[i] == v[n / 2 + 1]){
                b = i - 1;
                break;
            }
        }
        for(i = g + 1; i < b; i++){
            if(v[i] != v[i + 1]){
                if(i - g > g && b - i > g){
                    s = i - g;
                    b = b - i;
                    ok = 1;
                    break;
                }
            }
        }
        if(ok == 0){
            s = b = g = 0;
        }
        cout<< g <<" "<< s <<" "<< b <<"\n";
    }
}