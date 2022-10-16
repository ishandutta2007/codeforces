#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 200 * 1000 + 5;
long long ans[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, b;
    cin >> n >> b;
    queue< pair<int, long long> > q;
    int curid = -1;
    long long curd = 0, prevt = 0;
    for(int i = 0; i < n; i++) {
        long long t, d;
        cin >> t >> d;
        while(curid >= 0 && curd <= t - prevt) {
            prevt += curd;
            ans[curid] = prevt;
            if(q.empty()) {
                curid = -1;
                curd = 0;
            }
            else {
                curid = q.front().first;
                curd = q.front().second;
                q.pop();
            }
        }
        if(curid >= 0)
            curd -= t - prevt;
        if(curid == -1) {
            curid = i;
            curd = d;
        }
        else if((int)q.size() < b)
            q.push(make_pair(i, d));
        else
            ans[i] = -1;
        prevt = t;
    }
    while(curid >= 0) {
        prevt += curd;
        ans[curid] = prevt;
        if(q.empty()) {
            curid = -1;
            curd = 0;
        }
        else {
            curid = q.front().first;
            curd = q.front().second;
            q.pop();
        }
    }
    for(int i = 0; i < n; i++)
        cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}