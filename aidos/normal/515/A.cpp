#include <iostream>
using namespace std;
int main(){
int a, b, c;
cin >> a >> b >> c;
if(a < 0) c+=a;
else  c-= a;
if(b <0) c += b;
else c -= b;
if(c < 0 || c % 2 == 1) cout << "No";
else cout << "Yes";
return 0; 
}