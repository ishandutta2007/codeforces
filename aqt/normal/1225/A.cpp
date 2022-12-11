#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int da, db;
    cin >> da >> db;
    if(da == 9 && db == 1){
        cout << 9 << " " << 10 << endl;
    }
    else if(db-da == 1){
        cout << da << 9 << " " << db << 0 << endl;
    }
    else if(db == da){
        cout << da << 0 << " " << db << 1 << endl;
    }
    else{
        cout << -1 << endl;
    }
}