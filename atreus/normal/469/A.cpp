#include <bits/stdc++.h>

using namespace std;

bool mark[200];

int main(){
    ios_base::sync_with_stdio(false);
    int n, p;
    cin >> n >> p;
    for (int i = 1; i <= p; i++){
        int a;
        cin >> a;
        mark[a] = true;
    }
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++){
        int a;
        cin >> a;
        mark[a] = true;
    }
    for (int i = 1; i <= n; i++){
        if (mark[i] == false){
            cout << "Oh, my keyboard!" << endl;
            return 0;
        }
    }
    cout << "I become the guy." << endl;
}