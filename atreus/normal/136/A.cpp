#include <bits/stdc++.h>

using namespace std;

int main (){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[j] == i + 1)
                cout << j + 1 << " ";
}