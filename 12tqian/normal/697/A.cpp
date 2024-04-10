#include <bits/stdc++.h>
using namespace std;
int main(){
    int t, s, x;
    cin >> t;
    cin >> s;
    cin >>x;
    //cout << t <<s<<x;
    x = x-t;
    if(x == 0){
        cout << "YES";
        return 0;
    }
    if(x>1 && (x%s == 0 || x%s == 1)){
        cout << "YES";
        return 0;
    }
    cout << "NO";
    return 0;
}