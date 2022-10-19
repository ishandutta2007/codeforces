#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second

/*
#define int long long
#define inf 1e18
*/

#define ick cout<<"ickbmi32.9\n"

using namespace std;

mt19937 mt(time(nullptr));
int n, last;
string guess, rnd;
bool done = false;

int ask(string s) {
    for(int i = 0; i < n; i++) if(rnd[i] == '1') s[i] ^= 1;
    
    int a;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            cout << 'T';
        }
        else cout << 'F';
    }
    cout << endl;
    
    cin >> a;
    return a;
}

void solve() {
    done = false;
    
	cin >> n;
    
    rnd = "";
    guess = "";
    for(int i = 0; i < n; i++) rnd += ('0' + mt() % 2);
    for(int i = 0; i < n; i++) guess += '0';
    
    last = ask(guess);
    if(last == n) return;
    
    stack<pair<vector<int>, vector<int>>> opp;
    int nn = n;
    if(n & 1) {
        guess[n - 1] = '1';
        int aa = ask(guess);
        if(aa == n) return;
        if(aa < last) guess[n - 1] = '0';
        last = max(aa, last);
        nn--;
    }
    
    vector<int> chg;
    
    for(int i = 0; i < nn; i += 2) {
        guess[i] = guess[i + 1] = '1';
        int aa = ask(guess);
        if(aa == n) return;
        if(aa - last == 2) {
            chg.pb(i);
            chg.pb(i + 1);
        }
        else if(aa - last == 0) {
            vector<int> t, tt;
            t.pb(i); tt.pb(i + 1);
            opp.push(mp(t, tt));
        }
        guess[i] = guess[i + 1] = '0';
    }
    
    while(opp.size() >= 2) {
        auto a = opp.top();
        opp.pop();
        auto b = opp.top();
        opp.pop();
        for(auto x: a.fi) {
            guess[x] = '1';
        }
        for(auto x: b.fi) {
            guess[x] = '1';
        }
        int aa = ask(guess);
        if(aa == n) return;
        if(aa - last == a.fi.size() + b.fi.size()) {
            for(auto x: a.fi) {
                chg.pb(x);
            }
            for(auto x: b.fi) {
                chg.pb(x);
            }
        }
        else if(aa - last == -a.fi.size() - b.fi.size()) {
            for(auto x: a.se) {
                chg.pb(x);
            }
            for(auto x: b.se) {
                chg.pb(x);
            }
        }
        else if(a.fi.size() == b.fi.size()) {
            for(auto x: a.fi) {
                guess[x] = '0';
            }
            for(auto x: b.fi) {
                guess[x] = '0';
            }
            for(auto x: b.fi) {
                a.se.pb(x);
            }
            for(auto x: b.se) {
                a.fi.pb(x);
            }
            opp.push(a);
            continue;
        }
        else {
            if(aa - last == a.fi.size() - b.fi.size()) {
                for(auto x: a.fi) {
                    chg.pb(x);
                }
                for(auto x: b.se) {
                    chg.pb(x);
                }
            }
            else {
                for(auto x: a.se) {
                    chg.pb(x);
                }
                for(auto x: b.fi) {
                    chg.pb(x);
                }
            }
        }
        for(auto x: a.fi) {
            guess[x] = '0';
        }
        for(auto x: b.fi) {
            guess[x] = '0';
        }
    }
    
    if(opp.size() == 1) {
        auto a = opp.top();
        opp.pop();
        for(auto x: a.fi) {
            guess[x] = '1';
        }
        int aa = ask(guess);
        if(aa == n) return;
        if(aa > last) {
            for(auto x: a.fi) {
                chg.pb(x);
            }
        }
        else {
            for(auto x: a.se) {
                chg.pb(x);
            }
        }
        for(auto x: a.fi) {
            guess[x] = '0';
        }
    }

    for(auto x: chg) {
        guess[x] = '1';
    }
    
    ask(guess);
}
signed main(){
    solve();
    return 0;
}