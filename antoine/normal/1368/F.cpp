#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = 1009;
int n;
int a[MxN + 9];

int simul(const int k) {
//    int res = 0;
//
//    static int a[MxN + 9];
//    fill(a, a + n, 0);
//
//    return res;

return n - (n+k-1)/k + 1 - k;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    cin >> n;
    if( n <= 2) {
        cout << 0;
        return 0;
    }

    int bestK = 1;
    int bestRes = 0;
    for(int k = 2; k < n; ++k) {
        const int res  = simul(k);
        if(res > bestRes) {
            bestRes = res;
            bestK = k;
        }
    }

    const int k = bestK;
    DBG(k);
    DBG(bestRes);

    memset(a, 0, sizeof a);
    for(;;) {

        {
            vector<int> v;
            for (int i = 0; i < n && (int)v.size() < k; ++i)
                if (i % k && !a[i]) {
                    a[i] = 1;
                    v.push_back(i);
                }
            for(int i = 0; i < n && (int)v.size() < k; i += k)
                if(!a[i]) {
                    a[i] = 1;
                    v.push_back(i);
                }

            cout << (int)v.size() << '\n';
                for(int x : v)
                    cout << x + 1 << ' ';
                cout << endl;
        }


        int resp;
        cin >> resp;
        assert(resp != -1);
        --resp;
        int cnt = 0;
        for(int i = 0; i < k; ++i) {
            int &x = a[(i + resp) % n];
            if(x) {
                x = 0;
                ++cnt;
            }
        }
        if(cnt == k) {
            cout << 0;
            return 0;
        }
    }
    return 0;
}