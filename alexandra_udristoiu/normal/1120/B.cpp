#include<iostream>
#define DIM 100005
using namespace std;
int n, i, nr, j;
long long sol;
char s[DIM], b[DIM];
int a[DIM];
void op(int i, int num, int t){
    sol += num;
    a[i] += num * t;
    a[i + 1] += num * t;
}
void solve(int i, int t){
    if(nr >= 100000){
        return;
    }
    if(a[i + 1] + t < 0){
        solve(i + 1, 1);
    }
    if(a[i + 1] + t > 9){
        solve(i + 1, -1);
    }
    a[i] += t;
    a[i + 1] += t;
    if(nr < 100000){
        nr++;
        cout<< i <<" "<< t <<"\n";
    }
}
int main(){
    cin>> n;
    cin>> s + 1;
    cin>> b + 1;
    for(i = 1; i <= n; i++){
        a[i] = s[i] - '0';
        b[i] -= '0';
    }
    for(i = 1; i < n; i++){
        if(a[i] < 0){
            op(i, -a[i], 1);
        }
        if(a[i] > 9){
            op(i, a[i] - 9, -1);
        }
        if(a[i] > b[i]){
            op(i, a[i] - b[i], -1);
        }
        else{
            op(i, b[i] - a[i], 1);
        }
    }
    if(a[n] != b[n]){
        cout<< -1;
    }
    else{
        cout<< sol <<"\n";
        for(i = 1; i <= n; i++){
            a[i] = s[i] - '0';
        }
        for(i = 1; i < n && nr < 100000; i++){
            if(a[i] < b[i]){
               while(a[i] != b[i] && nr < 100000){
                    solve(i, 1);
                }
            }
            else{
                while(a[i] != b[i] && nr < 100000){
                    solve(i, -1);
                }
            }
        }
    }
}