#include <iostream>
using namespace std;

int main(){
 int x,ans = 0;
 cin >> x;
 for(; x; ans += x&1, x /= 2);
 cout << ans << endl;
}