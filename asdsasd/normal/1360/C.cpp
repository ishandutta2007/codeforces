#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    int even = 0;
    int odd = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if (a[i] % 2 == 0) even++;
        else odd++;
    }
    if(even % 2 == 0 && odd % 2 == 0){
        cout << "YES" << endl;
        return;
    }
    sort(a.begin(), a.end());
    for(int i = 1; i < n; i++){
        if(a[i] - a[i - 1] == 1){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}
int main(void){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}