#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    ll n,m;
    cin >> n >> m;
    cout << min(n,m)+1 << endl;
    for(int i  = 0 ;i <= min(n,m);i++) cout << n-i << " " << i << endl;
    return 0;
}
//2 3
//3 3 7 2
//3 4 2 5