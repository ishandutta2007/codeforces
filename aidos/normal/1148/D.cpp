#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)3e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, k;
int a[maxn];
int b[maxn];
bool cmpA(int i, int j) {
    return a[i] < a[j];
}
bool cmpB(int i, int j) {
    return a[i] > a[j];
}
void solve() {
    cin >> n;
    vector<int> A, B;
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        if(a[i] > b[i]) A.push_back(i);
        else if(a[i] < b[i]) B.push_back(i);
    }
    sort(A.begin(), A.end(), cmpA);
    sort(B.begin(), B.end(), cmpB);
    if(A.size() < B.size()) A = B;
    cout << A.size() << "\n";
    for(int id: A) cout << id + 1 << " ";
}


int main() {
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