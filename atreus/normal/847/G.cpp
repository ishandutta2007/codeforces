#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int h = 0;
    for(int i = 0; i < 7; i++){
        int m = 0;
        for(int j = 0; j < n; j++){
            if(a[j][i] == '1'){
                m++;
            }
        }
        if(m > h){
            h = m;
        }
    }
    cout << h;
}