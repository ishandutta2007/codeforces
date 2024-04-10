#include<iostream>
using namespace std;
int n, i, j;
int d[100005], num[100005];
char c;
int main(){
    cin>> n;
    if(n == 0){
        cout<<"a";
        return 0;
    }
    d[0] = 1;
    d[1] = 2;
    num[1] = 1;
    for(i = 2; i <= n; i++){
        num[i] = 1000000;
        for(j = 1; j * (j - 1) / 2 <= i; j++){
            if(d[i - j * (j - 1) / 2] != 0){
                if(num[i - j * (j - 1) / 2] + 1 < num[i]){
                    num[i] = num[i - j * (j - 1) / 2] + 1;
                    d[i] = j;
                }
            }
        }
    }
    c = 'a';
    while(n != 0){
        for(i = 1; i <= d[n]; i++){
            cout<< c;
        }
        c++;
        n -= d[n] * (d[n] - 1) / 2;
    }
    return 0;
}