#include <bits/stdc++.h>
#include <math.h>

using namespace std;
typedef long long ll;

int main(){
    ll n,a;
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> a;
        if(a % 2 == 0) cout << a-1 << " ";
        else cout << a << " ";
    }
    cout << endl;
    return 0;
}