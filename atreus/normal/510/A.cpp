#include <bits/stdc++.h>

using namespace std;

string s[100];

int main(){
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i += 2){
        for (int j = 0; j < m; j++){
            s[i] += '#';
        }
    }
    for (int i = 1; i < n; i += 2){
        for (int j = 0; j < m; j++){
            s[i] += '.';
        }
        if (i % 4 == 3)
            s[i][0] = '#';
        if (i % 4 == 1)
            s[i][m - 1] = '#';
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << s[i][j];
        }
        cout << endl;
    }
}