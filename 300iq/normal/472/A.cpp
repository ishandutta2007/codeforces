#include <iostream>

using namespace std;
bool isntesasy(int n){
for(int i = 2; i < n; i++){
    if(n%i==0){
                return true;
        break;

    }
    else{

    }
}
return false;
}
int main()
{
    int n, a, b;
    cin >> n;
    a = 0;
    b = 0;
    for(int i = 0; i <= n; i++){


        if(isntesasy(((n)-i)) && isntesasy(i)){
           cout<<(n)-i<<" " << i;
        break;
           }
        else{

        }


    }
}