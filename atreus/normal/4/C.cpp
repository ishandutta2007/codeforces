#include <bits/stdc++.h>

using namespace std;

map <string, int> m;

int main (){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        if (m[s] > 0){
            cout << s << m[s] << endl;;
            m[s] ++;
        }
        else{
            cout << "OK" << endl;
            m[s] ++;
        }
    }
}