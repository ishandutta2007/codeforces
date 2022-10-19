#include <iostream>
using namespace std;

void printit(int n){
    if(n>=5)
        cout << "-O|";
    else
        cout << "O-|";
    for(int a=0; a<5; a++){
        if(a==n%5){
            cout << "-";
        }
        else
            cout << "O";
    }
    cout << endl;
        
}

void soroban(int n){
    printit(n%10);
    if(n>=10)
        soroban(n/10);
    
}

int main() {
    int n;
    cin >> n;
    soroban(n);
    return 0;
}