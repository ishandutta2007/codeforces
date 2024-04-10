#include <iostream>
#include <cmath>
using namespace std;
int main(){
int a, b, c;
cin >> a >> b >> c;
cout << min(min(a, b), (a+b)/3);
return 0;
}