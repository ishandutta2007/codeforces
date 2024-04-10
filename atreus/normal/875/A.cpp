#include <bits/stdc++.h>

using namespace std;

int sumdigits(int n){
    int k = 0;
    while (n > 0){
        k += n % 10;
        n /= 10;
    }
    return k;
}

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int cnt = 0;
    vector <int> v;
    for (int i = max(n - 81, 1); i <= n; i++){
        if (i + sumdigits(i) == n){
            cnt ++;
            v.push_back(i);
        }
    }
    cout << cnt << endl;
    for (int i = 0; i < cnt; i++)
        cout << v[i] << endl;
    return 0;
}