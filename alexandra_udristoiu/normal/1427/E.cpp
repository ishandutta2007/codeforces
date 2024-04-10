#include<iostream>
using namespace std;
int x, i, nr;
long long y, p[25], z, t;
struct str{
    long long a, b;
    char s;
};
str w[100000];
int main(){
    cin>> x;
    p[0] = x;
    for(i = 1; i <= 20; i++){
        p[i] = 2 * p[i - 1];
        w[++nr] = {p[i - 1], p[i - 1], '+'};
    }
    y = x;
    for(i = 1; i <= 20; i++){
        if( ( (y >> i) & 1) == 1){
            w[++nr] = {y, p[i], '^'};
            y ^= p[i];
        }
    }
    z = x + y;
    t = x ^ y;
    w[++nr] = {x, y, '+'};
    w[++nr] = {x, y, '^'};
    w[++nr] = {z, t, '^'};
    z ^= t;
    w[++nr] = {z, z, '+'};
    w[++nr] = {z, z + z, '^'};
    t = ( (z + z) ^ z);
    w[++nr] = {z, t, '+'};
    z += t;
    while(y != 1){
        for(t = 2; t <= y; t *= 2){
            if( (t & y) == t){
                while(z < t){
                    w[++nr] = {z, z, '+'};
                    z += z;
                }
                w[++nr] = {z, y, '^'};
                y ^= z;
            }
        }
    }


    cout<< nr <<"\n";
    for(i = 1; i <= nr; i++){
        cout<< w[i].a <<" "<< w[i].s <<" "<< w[i].b <<"\n";
    }
}