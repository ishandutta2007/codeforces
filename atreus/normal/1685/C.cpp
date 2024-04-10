#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 10;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> pref;
    pref.push_back(0);
    for(char c : s) {
        pref.push_back(pref.back() + (c == '(' ? 1 : -1));
    }
    assert(pref.back() == 0);
    int neg1 = -1, neg2 = -1, mx1 = 0, mx2 = 0;
    int mx = 0;
    int N = 2*n+1;
    assert(pref.size() == N);
    for(int i = 0; i < N; i++) {
        if(mx < pref[i]) {
            mx1 = mx2 = i;
            mx = pref[i];
        }
        if(mx == pref[i]) {
            mx2 = i;
        }
        if(pref[i] < 0) {
            neg2 = i;
            if(neg1 == -1)
                neg1 = i;
        }
    }

    // for(int i = 0; i < N; i++)
    //     cout << pref[i] << " ";
    // cout << endl;

    if(neg1 == -1) { // case 0
        cout << 0 << "\n";
        return;        
    }
    int l = 0, r = N-1;
    for(int i = 0; i < neg1; i++) {
        if(pref[i] > pref[l])
            l = i;
    }
    for(int i = N-1; i > neg2; i--) {
        if(pref[i] > pref[r])
            r = i;
    }
    if(pref[l] + pref[r] >= mx) {
        cout << 1 << "\n" << l+1 << " " << r << "\n";
    } else {
        cout << 2 << "\n" << 1 << " " << mx2 << "\n" << mx2+1 << " " << N-1 << "\n"; 
    }
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int q;
    cin >> q;
    while(q--) {
        solve();
    }
}