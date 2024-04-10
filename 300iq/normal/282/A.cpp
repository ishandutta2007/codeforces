#include <bits/stdc++.h>

using namespace std;
int counter = 0;
int main(){
    string f;
    int x = 0;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> f;
        if(f[1] == '+'){
            x++;
        }
        else{
            x--;
        }
    }
    cout << x;
}