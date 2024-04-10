#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void){
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        int l = max(max(a, b), 2 * min(a, b));
        cout << l * l << endl;
    }
    return 0;
}