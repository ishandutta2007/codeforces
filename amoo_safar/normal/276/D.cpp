#include<iostream>
#include<math.h>
#include<stdint.h>
using namespace std;
int main(){
    int64_t a,b;
    cin >> a >> b;
    if(a==b) cout << 0;
    else cout << (long long)pow(2,(64-__builtin_clzll(a^b)))-1 << endl;
    return 0;
}