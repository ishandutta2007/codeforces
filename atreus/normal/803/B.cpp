#include <bits/stdc++.h>

using namespace std;

int a[211111],lef[211111], rig[211111];

int main (){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int b = -100000000;
    for (int i = 0; i < n; i++){
        if (a[i] == 0)
            b = i;
        lef[i] = i - b;
    }
    b = 1000000;
    for (int i = n - 1; i >= 0; i--){
        if (a[i] == 0)
            b = i;
        rig[i] = b - i;
    }
    for (int i = 0; i < n; i++){
        cout << min(lef[i], rig[i]) << " ";
    }
}