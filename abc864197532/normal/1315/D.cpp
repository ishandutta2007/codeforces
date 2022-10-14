#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
#define pli pair<lli,int> 
#define X first
#define Y second

int main () {
    int n;
    cin >> n;
    vector <pii> input(n);
    fop (i,0,n) cin >> input[i].X;
    fop (i,0,n) cin >> input[i].Y;
    sort(input.begin(), input.end());
    lli ans = 0;
    priority_queue<int> q;
    lli all = 0;
    int now = 0, h = input[0].X;
    while (now < n) {
        while (q.size() and h != input[now].X) {
            all -= q.top();
            q.pop();
            ans += all;
            h++;
        }
        h = input[now].X;
        while (now < n and h == input[now].X) {
            q.push(input[now].Y);
            all += input[now].Y;
            now++;
        }
        all -= q.top();
        q.pop();
        ans += all;
        h++;
    }
    while (q.size()) {
        all -= q.top();
        q.pop();
        ans += all;
    }
    cout << ans << endl;
}