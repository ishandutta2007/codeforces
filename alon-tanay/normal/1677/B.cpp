#include <bits/stdc++.h>
#define ll long long
#define pl pair<ll,ll>
#define pi pair<int,int>
#define f first
#define s second
#define vi vector<int>
#define vl vector<ll>
#define ld long double

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        int nm = n * m;
        vector<int> seq(nm);
        for(int i = 0; i < nm; i ++) {
            char c;
            cin >> c;
            if(c == '1') {
                seq[i] = 1;
            }
        }
        vector<int> dif(nm);
        vector<int> difM(nm);
        vector<int> res(nm);
        for(int i = 0; i < m; i ++) {
            for(int j = i; j < nm; j += m) {
                if(seq[j]) {
                    dif[j] ++;
                    break;
                }
            }
        }
        int cur = 0;
        for(int i = 0; i < nm; i ++) {
            cur -= (i-m<0 ? 0 : seq[i-m]);
            cur += seq[i];
            if(cur) { difM[i] ++; } 
        }
        // for(int i = 0; i < nm; i ++) {
        //     cout << dif[i] << " ";
        // }
        // cout << "\n";
        vector<int> curM(m);
        cur = 0;
        for(int i = 0; i < nm; i ++) {
            cur += dif[i];
            curM[i%m] += difM[i];
            cout << (cur + curM[i%m]) << " ";
        }
        cout << "\n";
    }
    return 0;
}