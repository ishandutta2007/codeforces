#include <bits/stdc++.h>

using namespace std;

int n, c0, c1;

int query(int c0) {
    cout << "? ";
    for(int i = 0; i < c0; i++) cout << 0;
    for(int i = 0; i < n - c0; i++) cout << 1;
    cout << endl;
    int ret;
    cin >> ret;
    return ret;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    c0 = query(0);
    c1 = n - c0;

    int first = query(1);
    if(first == c0 + 1) {
        int bl = 2, br = n;
        while(bl < br) {
            int bm = (bl + br) / 2;
            int x = query(bm);
            if(x == bm + c0) bl = bm + 1;
            else br = bm;
        }
        cout << "! " << bl << ' ' << 1 << endl;
    } else {
        int bl = 2, br = n;
        while(bl < br) {
            int bm = (bl + br) / 2;
            int x = query(bm);
            if(x == c0 - bm) bl = bm + 1;
            else br = bm;
        }
        cout << "! " << 1 << ' ' << bl << endl;
    }
}