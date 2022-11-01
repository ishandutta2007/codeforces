#include <bits/stdc++.h>

using namespace std;

bool root3(long long n) {
    long long bl = 1, br = 1000000;
    while(bl < br) {
        long long bm = (bl + br) / 2;
        if(bm * bm * bm < n)
            bl = bm + 1;
        else
            br = bm;
    }
    return bl * bl * bl == n;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    while(n--) {
        long long a, b;
        cin >> a >> b;
        cout << (a * a % b == 0 && b * b % a == 0 && root3(a * a / b) && root3(b * b / a) ? "Yes\n" : "No\n");
    }
}