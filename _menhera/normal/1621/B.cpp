#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    const int INF = 1e9+1;
    int T; cin >> T; while(T--) {
        int N; cin >> N;
        int minv = INF, maxv = 0;
        int minc = INF, maxc = INF, tot = 2*INF;
        while(N--)
        {
            int a, b, c; cin >> a >> b >> c;
            for(int v: {a, b})
            {
                if(minv > v) minc = c, minv = v, tot = 2*INF;
                if(minv == v) minc = min(minc, c);

                if(maxv < v) maxc = c, maxv = v, tot = 2*INF;
                if(maxv == v) maxc = min(maxc, c);
            }
            if(a == minv && b == maxv) tot = min(tot, c);
            cout << min(minc+maxc, tot) << '\n';
        }
    }
}