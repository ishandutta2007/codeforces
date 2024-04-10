#include <iostream>

using namespace std;

int main (){
    int n, cnt = 0;
    cin >> n;
    string s[n];
    for (int i = 0; i < n; i++){
        cin >> s[i];
        if (s[i] == "X++" || s[i] == "++X")
            cnt++;
        else
            cnt--;
    }
    cout << cnt << endl;
}