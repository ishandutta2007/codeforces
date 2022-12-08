#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
#define pl pair<ll,ll>
#define ld long double

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    string t;
    cin >> s;
    cin >> t;
    int lft = 0;
    vector<int> cntS(26);
    vector<int> cntT(26);
    vector<int> cntC(26);
    for(char c : s) {
        if(c == '?') { lft ++; }
        else {
            cntS[c-'a'] ++;
        }
    }
    for(char c : t) {
        cntT[c-'a'] ++;
    }
    int i = 0;
    for(; ; i ++) {
        bool fail = false;
        for(int j = 0; j < 26; j ++) {
            if(cntS[j] >= cntT[j]) {
                cntS[j] -= cntT[j];
            } else if(cntT[j]-cntS[j] <= lft) {
                lft -= cntT[j]-cntS[j];
                cntC[j] += cntT[j]-cntS[j];
                cntS[j] = 0;
            } else {
                fail = true;
                break;
            }
        }
        if(fail) { break;}
    }
    for(char c : s) {
        if(c == '?') {
            int i = 0;
            for(; i < 25; i ++) {
                if(cntC[i]) {
                    cntC[i] --;
                    break;
                }
            }
            cout << (char('a'+i));
        } else {
            cout << c;
        }
    }
}