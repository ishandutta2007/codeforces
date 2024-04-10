#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
string x[] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "B", "H"};
string s;
int a[3];
int p[3];
int dis(int x, int y) {
    int z = y - x;
    if(z < 0) z += 12;
    return z;
}
void solve() {
    for(int i = 0; i < 3; i++) {
        cin >> s;
        a[i] = 0;
        while(x[a[i]] != s) ++a[i];
        p[i] = i;
    }
    do{
        if(dis(a[p[0]], a[p[1]]) == 4 && dis(a[p[1]], a[p[2]]) == 3 && dis(a[p[0]], a[p[2]]) == 7) {
            cout << "major";
            return;
        }
        if(dis(a[p[0]], a[p[1]]) == 3 && dis(a[p[1]], a[p[2]]) == 4) {
            cout << "minor";
            return;
        }
    }while(next_permutation(p, p + 3));
    cout << "strange";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}