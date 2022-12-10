#include <bits/stdc++.h>
#define pi pair<int,int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t --) {
        int n;
        cin >> n;
        int a, b, con;
        vector<pi> ot(4);
        cout << "? 1 2 3" << endl;
        cin >> a;
        ot[3] = {a,4};
        cout << "? 1 2 4" << endl;
        cin >> a;
        ot[2] = {a,3};
        cout << "? 1 3 4" << endl;
        cin >> a;
        ot[1] = {a,2};
        cout << "? 2 3 4" << endl;
        cin >> a;
        ot[0] = {a,1};
        sort(ot.begin(), ot.end());
        a = ot[0].second;
        b = ot[1].second;
        con = ot[2].second;
        int dist = ot[3].first;
        for(int i = 5; i <= n; i ++) {
            cout << "? " << con << " " << a << " " << i << endl;
            int disA;
            cin >> disA;
            cout << "? " << con << " " << b << " " << i << endl;
            int disB;
            cin >> disB;
            if(disB > disA) {
                if(disB > dist) {
                    a = i;
                    dist = disB;
                }
            } else {
                if(disA > dist) {
                    b = i;
                    dist = disA;
                }
            }
        }
        cout << "! " << a << " " << b << endl;
    }
    return 0;
}