#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)4e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, q;
int a[maxn];
int L[maxn], R[maxn];
void solve(){
    cin>> n >> q;
    int mx = 0;
    int mi = q + 1;
    for(int i =1; i <= n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
        mi = min(mi, a[i]);
    }
    if(mx == q) {

    } else if(mi > 0) {
        cout << "NO\n";
        return;
    } else {
        int found = 0;
        for(int i = 1; i  <= n; i++) {
            if(a[i] == 0) {
                a[i] = q;
                found = 1;
                break;
            }
        }
        if(!found) {
            cout << "NO\n";
            return;
        }
    }
    int last = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) {
            a[i] = last;
        }
        last = a[i];
    }
    last = 1;
    for (int i = n; i >= 1; i--) {
        if (a[i] == 0) a[i] = last;
        last = a[i];
    }
    for(int i = 1; i <= n; i++) {
        R[a[i]] = i;
    }
    for(int i = n; i >= 1; i--) {
        L[a[i]] = i;
    }
    vector<int> st;
    for(int i = 1; i <= n; i++) {
        if(R[a[i]] == i) {
            while(st.size() > 0 && st.back() >= L[a[i]]) {
                if(a[st.back()] < a[i]) {
                    cout<< "NO\n";
                    return;
                }
                st.pop_back();
            }
        }
        st.emplace_back(i);
    }
    cout << "YES\n";
    for(int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
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