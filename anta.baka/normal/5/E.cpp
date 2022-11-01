#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, a[1000000], mx;
ll ret;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i]; mx = max(mx, a[i]);
    }
    vector<int> z;
    for(int i = 0; i < n; i++) {
        if(a[i] == mx) {
            for(int j = i; j < n; j++) a[j - i] = a[j];
            for(int j = 0; j < i; j++) a[n - i + j] = z[j];
            break;
        }
        z.push_back(a[i]);
    }
    vector<int> st;
    for(int i = 0; i < n; i++) {
        while(!st.empty() && st.back() < a[i]) {
            ret++;
            st.pop_back();
        }
        st.push_back(a[i]);
        int lf = 0, rg = st.size() - 1;
        while(lf < rg) {
            int md = (lf + rg) / 2;
            if(st[md] == a[i]) rg = md;
            else lf = md + 1;
        }
        ret += st.size() - lf - 1;
        if(lf != 0) ret++;
    }
    set<int> setik;
    if(st.size() >= 2 && st[0] == st[1])
        for(int x : st) ret += (x != mx);
    else for(int x : st) {
        setik.insert(x);
        if(setik.size() >= 3) ret++;
    }
    cout << ret;
}