#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, p = 0, l = 0, o = 0;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int a;
        cin >> a;
        if (a % 3 == 0)
            p ++;
        if (a % 3 == 1)
            l ++;
        if (a % 3 == 2)
            o ++;
    }
    int ans = min(l, o);
    ans += p / 2;
    cout << ans << endl;
}