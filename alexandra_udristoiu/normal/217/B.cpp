#include<iostream>
#define DIM 1000005
using namespace std;
int n, r, i, minim;
char s[DIM], sol[DIM];
void solve(int x, int y){
    int nr = n;
    s[1] = 'T';
    while(nr > 1 && x >= 1 && y >= 1){
        if(x >= y){
            s[nr] = 'T';
            x -= y;
        }
        else{
            s[nr] = 'B';
            y -= x;
        }
        nr--;
    }
    if(nr == 1 && x == 1 && y == 1){
        int i, num = 0;
        for(i = 2; i <= n; i++){
            if(s[i] == s[i - 1]){
                num++;
            }
        }
        if(num < minim){
            minim = num;
            for(i = 1; i <= n; i++){
                sol[i] = s[i];
            }
        }
    }
}
int main(){
    cin>> n >> r;
    minim = n + 2;
    for(i = 1; i <= r; i++){
        solve(i, r);
        solve(r, i);
    }
    if(minim == n + 2){
        cout<<"IMPOSSIBLE";
    }
    else{
        cout<< minim <<"\n";
        cout<< sol + 1;
    }
}