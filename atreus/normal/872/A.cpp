#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <vector>
#include <map>
#include <cmath>
#include <set>
#include <queue>

using namespace std;

int a[20], b[20], lis[20], lis2[20];

int main (){
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        lis[a[i]] ++;
    }
    for (int i = 0; i < m; i++){
        cin >> b[i];
        lis2[b[i]] ++;
    }
    for (int i = 1; i <= 9; i++){
        if (lis[i] == 1 && lis2[i] == 1){
            cout << i << endl;
            return 0;
        }
    }
    bool cur1 = false, cur2 = false;
    for (int i = 1; i <= 9; i++){
        if (lis[i] == 1 && cur2 == true){
            cout << i << endl;
            return 0;
        }
        if (lis[i] == 1 && cur1 == true)
            continue;
        if (lis2[i] == 1 && cur2 == true)
            continue;
        if (lis2[i] == 1 && cur1 == true){
            cout << i << endl;
            return 0;
        }
        if (lis[i] == 1 && cur2 == false){
            cout << i;
            cur1 = true;
        }
        if (lis2[i] == 1 && cur1 == false){
            cout << i;
            cur2 = true;
        }
    }


}