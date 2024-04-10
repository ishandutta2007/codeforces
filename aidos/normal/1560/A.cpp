#include <bits/stdc++.h>

using namespace std;
string s;
int n;
int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cin >> n;
        int t = 1;
        while(n > 0) {
            if(t % 3 == 0 || t % 10 == 3) {
                t++;
            } else {
                n--;
                t++;
            }
        }
        cout << t - 1 << "\n";  
    }
}