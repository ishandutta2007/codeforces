#include <iostream>
#include <algorithm>

using namespace std;

int a[1000], n, counter;

int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    while (true){
        int tmp = 0, tmpc;
        for (int i = 1; i < n; i++)
        {
        if (a[i] > tmp)
        {
                tmpc = i;
                tmp = a[i];
        }
        }
        if (tmp < a[0])
        {
            cout << counter;
            return 0;
        }
        else
        {
            a[0]++;
            a[tmpc]--;
            counter++;
        }
    }
}