#include <bits/stdc++.h>

using namespace std;

int T;

int main(){
    cin >> T;
    while(T--){
        int a, b, cnt = 0;
        cin >> a >> b;
        if(a > b){
            swap(a, b);
        }
        while(a != 0){
            cnt += b/a;
            swap(a, b);
            a = a%b;
        }
        cout << cnt << endl;
    }
}