#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

int n, m;
vector<int> a;


bool f(const int mid) {
    int prev = 0;
    for(const int &x :a){
        if(x<=prev) {
            if(prev - x > mid)
                return false;
        } else {
            if(m-x+prev > mid)
                prev = x;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    cin >> n >> m;
    a.resize(n);
    for(int &x :a)
        cin >> x;


    int lo = 0;
    int hi = m;
    while(lo < hi) {
        const int mid = (lo + hi) / 2;
        if(f(mid))
            hi=mid;
        else
            lo=mid+1;
    }
    cout << lo;
    return 0;
}