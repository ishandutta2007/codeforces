#include<iostream>
#include<cstring>
using namespace std;
int n, i;
long long maxim, val;
char a[100005][15];
long long solve(){
    long long val = 0;
    int x = 0, j = 4;
    while(a[i][j] >= '0' && a[i][j] <= '9'){
        x = x * 10 + a[i][j] - '0';
        j++;
    }
    i++;
    while(a[i][0] != 'e'){
        if(a[i][0] == 'a'){
            if(val != -1){
                val++;
            }
            i++;
        }
        else{
            long long val2 = solve();
            if(val2 == -1){
                val = -1;
            }
            else{
                if(val != -1){
                    val += val2;
                }
            }
        }
        if(val > maxim){
            val = -1;
        }
    }
    i++;
    if(val != -1){
        val *= x;
        if(val > maxim){
            val = -1;
        }
    }
    return val;
}
int main(){
    cin>> n;
    n++;
    a[1][0] = 'f';
    a[1][1] = 'o';
    a[1][2] = 'r';
    a[1][3] = ' ';
    a[1][4] = '1';
    for(i = 2; i <= n; i++){
        cin.get();
        cin.get(a[i], 12);
    }
    n++;
    a[n][0] = 'e';
    a[n][1] = 'n';
    a[n][2] = 'd';
    i = 1;
    maxim = (1LL << 32) - 1;
    val = solve();
    if(val == -1){
        cout<<"OVERFLOW!!!";
    }
    else{
        cout<< val;
    }
}