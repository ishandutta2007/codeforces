#include <bits/stdc++.h>

using namespace std;

stack <int> s;

int main(){
    ios_base::sync_with_stdio(false);
    int a, b;
    cin >> a >> b;
    while (b > a){
        if (b % 2 == 0){
            s.push(2);
            b /= 2;
        }
        else
        if (b % 10 == 1){
            s.push(1);
            b /= 10;
        }
        else
            return cout << "NO" << endl, 0;
    }
    if (b == a){
        cout << "YES" << endl << s.size() + 1 << endl << a << " ";
        while (!s.empty()){
            if (s.top() == 2){
                a *= 2;
                cout << a << " ";
            }
            else {
                a *= 10;
                a += 1;
                cout << a << " ";
            }
            s.pop();
        }
    }
    else
        cout << "NO" << endl;
}