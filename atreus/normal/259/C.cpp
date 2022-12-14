#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    string a;
    cin >> a;
    bool sheep = false;
    for (int i = 0; i < a.size(); i++){
        if (a[i] == '0')
            break;
        if (i == a.size() - 1){
            for (int j = 0; j < a.size() - 1; j++)
                cout << a[j];
            return 0;
        }
    }
    for (int i = 0; i < a.size(); i++){
        if (a[i] == '0' && !sheep){
            sheep = true;
            continue;
        }
        cout << a[i];
    }
}