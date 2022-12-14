#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;
int a[maxn + 100];

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort (a, a + n);
    int t = 0, cnt = 0;
    for (int i = 0; i < n; i++){
        if (a[i] >= t){
            cnt ++;
            t += a[i];
        }
    }
    cout << cnt << endl;
}