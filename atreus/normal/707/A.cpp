#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int n, m;
    bool cur = false;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            char a;
            cin >> a;
            if (a == 'Y' || a == 'C' || a == 'M')
                cur = true;
        }
    }
    if (cur == true)
        cout << "#Color" << endl;
    else
        cout << "#Black&White" << endl;
}