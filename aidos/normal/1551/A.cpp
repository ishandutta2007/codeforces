#include <bits/stdc++.h>

using namespace std;
string s;
int n;
int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cin >> n;
        int x = n/3;
        int y = n/3;
        if(n % 3 == 1) x++;
        else if(n % 3 == 2) y++;
        cout << x << " " << y << "\n";
    }
}