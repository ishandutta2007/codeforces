#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <vector>
#include <map>
#include <stack>

using namespace std;

int main (){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    if (n % 2 == 0){
        cout << (n / 2) * (n / 2) << endl;
        for (int i = 1; i <= n / 2; i++){
            for (int j = n / 2 + 1; j <= n; j++)
                cout << i << " " << j << endl;
        }
        return 0;
    }
    if (n % 2 == 1){
        cout << (n / 2) * (n / 2 + 1) << endl;
        for (int i = 1; i <= n / 2; i++){
            for (int j = n / 2 + 1; j <= n; j++)
                cout << i << " " << j << endl;
        }
    }
}