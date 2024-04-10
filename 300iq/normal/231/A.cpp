#include <bits/stdc++.h>

using namespace std;
int counter = 0;
int main(){
    int n, p, v, t;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> p >> v >> t;
        if(p + v + t >= 2){
            counter++;
        }
    }
    cout << counter;
}