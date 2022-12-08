#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> xs(n);
    for(int &x : xs) {
        cin >> x;
    }
    ll pw = 1;
    ll res = 0;
    ll sum = 0;
    for(int i = 0; i < 27; i ++) {
        vector<int> sub0;
        vector<int> sub1;
        for(int x : xs) {
            if(x&pw) {
                sub1.push_back(x&sum);
            } else {
                sub0.push_back(x&sum);
            }
        }
        sort(sub1.begin(),sub1.end());
        sort(sub0.begin(),sub0.end());
        int s0 = sub0.size();
        int s1 = sub1.size();
        ll cnt00 = 0;
        if(s0) {
            int r = s0 - 1;
            int over = 0;
            for(int l = 0; l < s0; l ++) {
                if(sub0[l] * 2 > sum) { over ++; }
                if(sub0[l] + sub0[0] <= sum) {
                    while(sub0[l] + sub0[r] > sum) { r --; }
                } else {
                    r = -1;
                }
                cnt00 += (s0-r-1);
            }
            cnt00 -= over;
            cnt00 /= 2;
        }
        ll cnt01 = 0;
        if(s1 > 0 && s0 > 0) {
            int r = s1 - 1;
            for(int l = 0; l < s0; l ++) {
                if(sub0[l] + sub1[0] > sum) { break; }
                while(sub0[l] + sub1[r] > sum) { r --; }
                cnt01 += (r+1);
            }
        }
        ll cnt11 = 0;
        if(s1) {
            int r = s1 - 1;
            int over = 0;
            for(int l = 0; l < s1; l ++) {
                if(sub1[l] * 2 > sum) { over ++; }
                if(sub1[l] + sub1[0] <= sum) {
                    while(sub1[l] + sub1[r] > sum) { r --; }
                } else {
                    r = -1;
                }
                cnt11 += (s1-r-1);
            }
            cnt11 -= over;
            cnt11 /= 2;
        }
        ll total = cnt00 + cnt01 + cnt11;
        if(total&1) {
            res += pw;
        }

        sum += pw;
        pw *= 2;
    }
    cout << res;
    return 0;
}