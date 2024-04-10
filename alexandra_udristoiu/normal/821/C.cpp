#include<iostream>
#define DIM 300005
using namespace std;
int n, i, x, nr1, nr2, p, sol;
int poz[DIM], aib[DIM];
char s[10];
void update(int x, int val){
    for(; x <= n; x += (x & -x)){
        aib[x] = max(aib[x], val);
    }
}
int query(int x){
    int sol = 0;
    for(; x >= 1; x -= (x & -x)){
        sol = max(sol, aib[x]);
    }
    return sol;
}
int main(){
    cin>> n;
    for(i = 1; i <= 2 * n; i++){
        cin>> s;
        if(s[0] == 'a'){
            cin>> x;
            nr1++;
            poz[x] = nr1;
            update(n - x + 1, nr1);
        }
        else{
            nr2++;
            if(query(n - nr2 + 1) > max(p, poz[nr2])){
                sol++;
                p = nr1;
            }
        }
    }
    cout<< sol;
    return 0;
}