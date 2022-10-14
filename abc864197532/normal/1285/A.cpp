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

int main() {
    int n, minn = 0, maxx = 0;
    string s;
    cin >> n >> s;
    fop (i,0,n) {
        if (s[i] == 'L') minn++;
        else maxx++;
    }
    cout << maxx + minn + 1 << endl;
}