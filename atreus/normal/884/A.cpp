#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;

int a[200];

int main(){
    ios_base::sync_with_stdio(false);
    int n, t;
    cin >> n >> t;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    long long ans = 0;
    for (int i = 0; i < n; i++){
        ans += 86400 - a[i];
        if (ans >= t){
            cout << i + 1 << endl;
            return 0;
        }
    }
}