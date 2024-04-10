#include <iostream>
using namespace std;

int main() {
    
    int a;
    cin>>a;
    int b;
    cin>>b;
    int c=0;
    for(int i=1; i<=a; i++){
        if(b%i==0){
            if(b/i<=a){
                c++;
            }
        }
    }
    cout << c;
    
    return 0;
}