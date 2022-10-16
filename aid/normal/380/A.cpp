#include <iostream>

using namespace std;

const int MAXN = 100 * 1000 + 5;
int a[MAXN];
long long len[MAXN];
pair<int, pair<int, int> > q[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> q[i].first;
        if(q[i].first == 1) {
            cin >> q[i].second.first;
            if(len[i] < MAXN)
                a[len[i]] = q[i].second.first;
            len[i + 1] = len[i] + 1;
        }
        else {
            cin >> q[i].second.first >> q[i].second.second;
            for(long long j = len[i]; j < MAXN &&
                    j < len[i] + q[i].second.first * q[i].second.second; j++)
                a[j] = a[(j - len[i]) % q[i].second.first];
            len[i + 1] = len[i] + q[i].second.first * q[i].second.second;
        }
    }
    int n;
    cin >> n;
    int j = 0;
    for(int i = 0; i < n; i++) {
        long long k;
        cin >> k;
        k--;
        while(len[j] <= k)
            j++;
        if(q[j - 1].first == 1)
            cout << q[j - 1].second.first << ' ';
        else
            cout << a[(k - len[j - 1]) % q[j - 1].second.first] << ' ';
    }
    cout << '\n';
    return 0;
}