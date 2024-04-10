#include<iostream>
using namespace std;
int i, pt, a, b, s;
int query(int a, int b){
    cout<<"? "<< a <<" "<< b <<"\n";
    cout.flush();
    int x;
    cin>> x;
    return x;
}
int main(){
    s = query(0, 0);
    for(i = 29; i >= 0; i--){
        if(s == 0){
            break;
        }
        pt = (1 << i);
        if(s == 1){
            if( query(a + pt, b + pt) == -1){
                a += pt;
                s = query(a, b);
            }
            else{
                if(query(a + pt, b) == -1){
                    a += pt;
                    b += pt;
                }
            }
        }
        else{
            if( query(a + pt, b + pt) == 1){
                b += pt;
                s = query(a, b);
            }
            else{
                if(query(a, b + pt) == 1){
                    a += pt;
                    b += pt;
                }
            }
        }
    }
    for(; i >= 0; i--){
        pt = (1 << i);
        if(query(a + pt, b) == -1){
            a += pt;
            b += pt;
        }
    }
    cout<<"! "<< a <<" "<< b <<"\n";
    cout.flush();
}