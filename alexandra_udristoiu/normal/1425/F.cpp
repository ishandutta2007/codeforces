#include<iostream>
using namespace std;
int n, p, u, sum, sum2, s12, s13, s23, i;
int v[1005];
int query(int p, int u){
    int x;
    cout<<"? "<< p <<" "<< u <<"\n";
    cout.flush();
    cin>> x;
    return x;
}
int main(){
    cin>> n;
    s12 = query(1, 2);
    s13 = query(1, 3);
    s23 = query(2, 3);
    v[2] = s12 + s23 - s13;
    v[1] = s12 - v[2];
    v[3] = s23 - v[2];
    sum = v[1] + v[2] + v[3];
    for(i = 4; i <= n; i++){
        sum2 = query(1, i);
        v[i] = sum2 - sum;
        sum = sum2;
    }
    cout<<"! ";
    for(i = 1; i <= n; i++){
        cout<< v[i] <<" ";
    }
}