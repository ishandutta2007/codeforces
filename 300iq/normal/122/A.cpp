#include <bits/stdc++.h>
#define INF 100000000
using namespace std;

int main(){
    int a[14] = {4, 7, 44, 47, 74, 77, 444, 447, 477, 774, 744, 747, 474, 777};
    int n;
    cin >> n;
    for(int i = 0; i < 14; i++){
        if(n % a[i] == 0){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}