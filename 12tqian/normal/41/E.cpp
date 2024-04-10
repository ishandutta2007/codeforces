#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    cout <<  (n*n)/4<<endl;
    for(int i = 1; i<= n/2; i++){
        for(int x = n/2+1; x<= n; x++){
            cout<< i<< " "<< x<< endl;
        }
    }
}