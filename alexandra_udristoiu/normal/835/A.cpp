#include<iostream>
using namespace std;
int s, t1, t2, v1, v2, x, y;
int main(){
    cin>> s >> v1 >> v2 >> t1 >> t2;
    x = s * v1 + t1 + t1;
    y = s * v2 + t2 + t2;
    if(x == y){
        cout<<"Friendship";
    }
    else{
        if(x < y){
            cout<<"First";
        }
        else{
            cout<<"Second";
        }
    }
    return 0;
}