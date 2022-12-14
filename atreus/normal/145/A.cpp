#include<bits/stdc++.h>

using namespace std;

int main(){
    string a, b;
    cin >> a >> b;
    int a4 = 0, b4 = 0;
    for (int i = 0; i < a.size(); i++){
        if (a[i] == '4')
            a4 ++;
        if (b[i] == '4')
            b4 ++;
    }
    if (a4 < b4){
        int ans = b4 - a4;
        for (int i = 0; i < a.size(); i++){
            if (a[i] == '4' && b[i] == '7')
                ans ++;
        }
        cout << ans << endl;
    }
    else {
        int ans = a4 - b4;
        for (int i = 0; i < a.size(); i++){
            if (a[i] =='7' && b[i] == '4')
                ans ++;
        }
        cout << ans << endl;
    }
}