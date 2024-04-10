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

vector <pair<pii, pii>> input;

bool Find(int n) {
    priority_queue <pii, vector <pii>, greater <pii>> q;
    set <int> index;
    multiset <int> R;
    multiset <int, greater <int>> L;
    fop (i,0,n) {
        while (q.size() and q.top().X < input[i].X.X) {
            int k = q.top().Y;
            index.erase(k);
            L.erase(input[k].Y.X);
            R.erase(input[k].Y.Y);
            q.pop();
        }
        if (R.size() and (*L.begin() > input[i].Y.Y or input[i].Y.X > *R.begin())) {
            return false;
        }
        q.push({input[i].X.Y, i});
        index.insert(i);
        L.insert(input[i].Y.X);
        R.insert(input[i].Y.Y);
    }
    return true;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    input.resize(n);
    fop (i,0,n) cin >> input[i].X.X >> input[i].X.Y >> input[i].Y.X >> input[i].Y.Y;
    sort(input.begin(), input.end());
    if (!Find(n)) {
        cout << "NO" << endl;
        return 0;
    }
    fop (i,0,n) input[i] = mp(mp(input[i].Y.X, input[i].Y.Y), mp(input[i].X.X, input[i].X.Y));
    sort(input.begin(), input.end());
    if (!Find(n)) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    return 0;
}