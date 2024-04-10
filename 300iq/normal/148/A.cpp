#include <iostream>
#include<math.h>
int counter = 0;
using namespace std;
int main()
{
long long k, l, m, n, d;
cin >> k >> l >> m >> n >> d;
long long dragons[d];
for(int i = 1; i <= d; i++){
    if(i%k==0||i%l==0||i%m==0||i%n==0){
    dragons[i-1] = 1;
    counter += 1;
    }
    else{
    dragons[i-1] = 0;
    }
}

cout<<counter;


}