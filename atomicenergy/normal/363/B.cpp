#include <iostream>
using namespace std;

int main() {
    int n, k;
    int b[150000];
    cin >> n >> k;
    int min = k*100;
    int minindex=0;
    int total=0;
    for(int a=0; a<n; a++){
        cin >> b[a];
        if(a<k-1){
            total+=b[a];
        }
        else{
            total-=b[a-k];
            total+=b[a];
            if(total<=min){
                min=total;
                minindex=a-k+2;
            }
            
        }
    }
    if(n==k){
        cout << 1;
    }
    else
        cout << minindex;
    
}