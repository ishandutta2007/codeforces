#include <iostream>
#include <cstdio>
using namespace std;


main(){
       
       long long n,k;
       cin >> n >> k;
       
       long long i = (n+1)/2;
       
       if(k <= i){
            
            cout << (2*k-1) << endl;
            
            }
            
            
       else {
            k -= i;
            cout << 2*k << endl;
            
            
            }
            
     }