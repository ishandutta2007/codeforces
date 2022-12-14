#include <iostream>
#include <cmath>

using namespace std;

string a;

int x[12];

int main(){
    cin >> a;
    for (int i = 0; i < a.size(); i++){
        for (int j = 0; j < a[i] - '0'; j++)
            x[j] += pow(10, a.size() - i - 1);
    }
    int ans = 0;
    for (int i = 0; i < 12; i++) {
        if (x[i] == 0)
            break;
        ans = i + 1;
    }
    cout << ans << endl;
    for (int i = 0; i < ans; i++)
        cout << x[i] << " ";
}