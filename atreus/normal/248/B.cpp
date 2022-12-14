#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    string a[6] = {"050", "080", "170", "020", "200", "110"};
    string ans = "1";
    int n;
    cin >> n;
    if (n >= 4){
        for (int i = 0; i < n - 4; i++)
            ans += '0';
        int b = (n + 2) % 6;
        ans += a[b];
    }
    else if (n == 3)
        ans = "210";
    else
        ans = "-1";
    cout << ans << endl;
}