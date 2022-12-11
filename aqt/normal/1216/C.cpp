#include <bits/stdc++.h>

using namespace std;

int x[6], y[6];

bool inside(int tx, int ty, int bl, int tr){
    return x[bl] <= tx && x[tr] >= tx && y[bl] <= ty && y[tr] >= ty;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i = 0; i<6; i++){
        cin >> x[i] >> y[i];
        x[i] *= 2, y[i] *= 2;
    }
    for(int i = x[0]; i<=x[1]; i++){
        if(!inside(i, y[0], 2, 3) && !inside(i, y[0], 4, 5)){
            cout << "YES" << endl;
            return 0;
        }
        if(!inside(i, y[1], 2, 3) && !inside(i, y[1], 4, 5)){
            cout << "YES" << endl;
            return 0;
        }
    }
    for(int i = y[0]; i<=y[1]; i++){
        if(!inside(x[0], i, 2, 3) && !inside(x[0], i, 4, 5)){
            cout << "YES" << endl;
            return 0;
        }
        if(!inside(x[1], i, 2, 3) && !inside(x[1], i, 4, 5)){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}