#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int h = a[1] - a[0];
    for(int i = 0; i < n - 1; i++){
        if(a[i + 1] - a[i] != h){
            cout << a[n - 1];
            return 0;
        }
    }
    cout << a[n - 1] + h;
}