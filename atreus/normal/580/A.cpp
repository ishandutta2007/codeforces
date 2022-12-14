#include<bits/stdc++.h>

using namespace std;

int main (){
    int n, l = 1;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n - 1; i++){
        int cnt = 1;
        for (int j = i + 1; j < n; j++){
            if (a[j] >= a[j - 1]){
                cnt++;
                i++;
            }
            else
                break;
        }
        if (cnt > l)
            l = cnt;
    }
    cout << l << endl;
}