#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int, int> 
#define X first
#define Y second
vector <int> input, id;

int main () {
    int n;
    cin >> n;
    input.resize(n);
    id.resize(n);
    fop (i,0,n) {
        cin >> input[i];
        if (input[i] < 0) input[i] = -input[i];
    }
    iota(id.begin(), id.end(), 0);
    sort(id.begin(), id.end(), [](int i, int j) {return input[i] > input[j];});
    int ans = 0;
    fop (i,0,n) {
        int a = 0, b = 0;
        fop (j,0,i) if (input[j] < input[i]) a++;
        fop (j,i+1,n) if (input[j] < input[i]) b++;
        ans += min(a, b);
    }
    cout << ans << endl;
}