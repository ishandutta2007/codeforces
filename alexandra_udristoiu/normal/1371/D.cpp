#include<iostream>
#include<queue>
using namespace std;
int t, n, k, i, u, nr, j, num, x;
char a[305][305];
queue<int> v[305];
int main(){
    cin>> t;
    for(; t; t--){
        cin>> n >> k;
        for(i = 0; i <= n; i++){
            if(!v[i].empty()){
                v[i].pop();
            }
        }
        for(i = 1; i <= n; i++){
            v[0].push(i);
            for(j = 1; j <= n; j++){
                a[i][j] = '0';
            }
        }
        u = 0;
        if(k % n == 0){
            cout<<"0\n";
        }
        else{
            cout<<"2\n";
        }
        x = 1;
        for(i = 1; i <= n; i++){
            num = k / n;
            if(i <= k % n){
                num++;
            }
            for(j = 1; j <= num; j++){
                if(x == n + 1){
                    x = 1;
                }
                a[i][x] = '1';
                x++;
            }
        }
        for(i = 1; i <= n; i++){
            for(j = 1; j <= n; j++){
                cout<< a[i][j];
            }
            cout<<"\n";
        }
    }
}