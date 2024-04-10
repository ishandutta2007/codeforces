#include <bits/stdc++.h>
using namespace std;

int main(){
    int a[8][8], counter, ans1 = 8, ans2 = 8;
    char tmp;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cin >> tmp;
            a[i][j] = (tmp == '.' ? 0 : tmp == 'W' ? 1 : 2);
        }
    }
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            counter = 0;
            if(a[i][j] == 1){
                for(int k = i - 1; k >= 0; k--){
                    if(a[k][j] == 0){
                        counter++;
                    }
                    else{
                        counter = INT_MAX;
                        break;
                    }
                }
                ans1 = min(counter, ans1);
            }
            else if(a[i][j] == 2){
                for(int k = i + 1; k < 8; k++){
                    if(a[k][j] == 0){
                        counter++;
                    }
                    else{
                        counter = INT_MAX;
                        break;
                    }
                }
                ans2 = min(counter, ans2);
            }
        }
    }
    cout << (ans1 <= ans2 ? 'A' : 'B');
}