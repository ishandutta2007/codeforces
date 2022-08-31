#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int maximum = 0;
    int zero = 0;
    int j = n-1;
    for(int i = n-1; i >= 0; i--){
        int tmp = a[i];
        a[i] = max(maximum + 1 - a[i], 0);
        maximum = max(maximum, tmp);
    }
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}