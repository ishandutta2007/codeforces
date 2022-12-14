#include <bits/stdc++.h>

using namespace std;

int a[120];

int main(){
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int cnt = 0;
    bool cur = false;
    for (int i = 0; i < n; i++){
        if (a[i] < x)
            cnt ++;
        else if(a[i] == x){
            cur = true;
            break;
        }
        else
            break;
    }
    int ans = x - cnt;
    if (cur == true)
        ans ++;
    cout << ans << endl;

}