#include <iostream>

using namespace std;

int main (){
    int n, k, p = 0;
    cin >> n >> k;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (s[i] == s[j])
                p++;
        }
        if (p > k){
            cout << "NO" << endl;
            return 0;
        }
        p = 0;
    }
    cout << "YES" << endl;
}