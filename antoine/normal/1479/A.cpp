#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;



int query(int x) {
    cout << "? " << x << endl;
    int res;
    cin >> res;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);


    int n;
    cin >> n;
    int lo = 1, hi = n;while(lo <hi) {
        int mid = (lo + hi) / 2;
        if(query(mid) > query(mid + 1))
            lo = mid + 1;
        else
            hi = mid;
    }
    cout << "! " << lo;

    return 0;
}