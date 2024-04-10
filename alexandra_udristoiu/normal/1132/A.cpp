#include<iostream>
using namespace std;
int nr1, nr2, nr3, nr4;
int main(){
    cin>> nr1 >> nr2 >> nr3 >> nr4;
    if(nr1 == nr4 && (nr3 == 0 || nr1 != 0) ){
        cout<< 1;
    }
    else{
        cout<< 0;
    }
}