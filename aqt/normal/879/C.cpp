#include <bits/stdc++.h>

using namespace std;

int typ[500005];
//1 = |, 2 = ^, 3 = &;
int N;
int arr[500005];

int main(){
    cin >> N;
    for(int i = 1; i<=N; i++){
        char c;
        cin >> c >> arr[i];
        if(c == '|'){
            typ[i] = 1;
        }
        if(c == '^'){
            typ[i] = 2;
        }
        if(c == '&'){
            typ[i] = 3;
        }
    }
    int a = 0, x = 0;
    for(int k = 0; k<10; k++){
        int one = 1, zero = 0;
        int bit = (1<<k);
        for(int i = 1; i<=N; i++){
            if(arr[i]&bit){
                if(typ[i] == 1){
                    one |= 1;
                    zero |= 1;
                }
                if(typ[i] == 2){
                    one ^= 1;
                    zero ^= 1;
                }
                if(typ[i] == 3){
                    one &= 1;
                    zero &= 1;
                }
            }
            else{
                if(typ[i] == 1){
                    one |= 0;
                    zero |= 0;
                }
                if(typ[i] == 2){
                    one ^= 0;
                    zero ^= 0;
                }
                if(typ[i] == 3){
                    one &= 0;
                    zero &= 0;
                }
            }
        }
        if(one == 0 && zero == 0){

        }
        else if(one == 1 && zero == 0){
            a += bit;
        }
        else if(one == 0 && zero == 1){
            a += bit;
            x += bit;
        }
        else{
            x += bit;
        }
    }
    cout << 2 << endl;
    cout << "& " << a << endl;
    cout << "^ " << x << endl;
}