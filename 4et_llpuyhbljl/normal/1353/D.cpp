#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<queue>
using namespace std;
int gcd(int i, int j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
inline int getint() {
    int val = 0;
    char c;
    while ((c = getchar()) && !(c >= '0' && c <= '9'));
    do {
        val = (val * 10) + c - '0';
    } while ((c = getchar()) && (c >= '0' && c <= '9'));
    return val;
}
const long long INF = 100000000000000;
const int Y = 100;
const int m = 997;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int>a(n);
        priority_queue<pair<int, long long>>q;
        q.push({ n,INF - 0 });
        for (int i = 1; i <= n; ++i) {
            int l;
            long long id;
            tie(l, id) = q.top();
            q.pop();
            id = INF - id;
            if (l == 1) {
                a[id] = i;
            }
            else {
                int tmpid = id + (l - 1) / 2;
                a[tmpid] = i;
                int l1 = tmpid - id;
                if (l1 != 0) {
                    q.push({ l1,INF - id });
                }
                l1 = l - l1 - 1;
                if (l1 != 0) {
                    id = tmpid + 1;
                    q.push({ l1,INF - id });
                }
            }
        }
        for (auto x : a)cout << x << " ";
        cout << endl;
    }
    return 0;
}
//