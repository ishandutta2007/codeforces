#include <bits/stdc++.h>

using namespace std;

int b[1000000 + 1000];

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> b[i];
    int k = 0, cnt = 0;
    for (int i = n - 1; i >= 0; i--){
        if (k == 0)
            cnt ++;
        if (b[i] >= k)
            k = b[i];
        else
            k --;
    }
    cout << cnt << endl;
}