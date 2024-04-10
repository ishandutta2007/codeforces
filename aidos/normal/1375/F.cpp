#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 100;
typedef long long ll;
pair<ll, int> a[10];
int main(){
    for(int i = 0; i < 3; i++) {
        cin >> a[i].first;
        a[i].second = i+1;
    }
    cout << "First" << endl;
    while(true) {
        sort(a, a + 3);
        ll y = a[2].first * 2 - a[0].first - a[1].first;
        cout << y << endl;
        int id;
        cin >> id;
        if(a[2].second == id) {
            a[2].first += y;
            continue;
        }
        if(a[1].second == id) {
            a[1].first += y;
            cout<<a[2].first - a[0].first << endl;
            cin >> id;
            break;
        }
        if(a[0].second == id) {
            a[0].first += y;
            cout<<a[2].first - a[1].first << endl;
            cin >> id;
            break;
        }
    }
}