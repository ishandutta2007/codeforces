#include <iostream>
using namespace std;
#define lli long long int
int main () {
    lli n,m,a,all=1;
    cin >> n >> m >> a;
    all*=((n-1)/a+1); 
    all*=((m-1)/a+1);
    cout << all << endl;
}