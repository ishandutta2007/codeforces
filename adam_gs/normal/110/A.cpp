#include <bits/stdc++.h>

using namespace std;

int main() {
    string x;
    cin >> x;
    int r = 0;
    for (int i = 0; i < x.size(); ++i) {
        if (x[i]-'0'==4 || x[i]-'0'==7) {
            ++r;
        }
    }
    if (r==0) {
        cout << "NO";
    } else {
        bool t = true;
        while (r>0) {
            if (r%10!=4 && r%10!=7) {
                t=false;
                break;
            }
            r/=10;
        }
        if (t==true) {
            cout << "YES";
        } else {
            cout << "NO";
        }
    }
}