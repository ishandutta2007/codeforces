#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)      (x).begin(),(x).end()
#define X           first
#define Y           second
#define sep         ' '
#define endl        '\n'
#define SZ(x)       ll(x.size())

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int q , n , a , b , c , d;
string s;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> q;
    while(q--){
        int cntA = 0 , cntB = 0;
        cin >> a >> b >> c >> d >> s;
        n = SZ(s);
        for(int i = 0 ; i < n ; i++){
            if(s[i] == 'A') cntA++;
            if(s[i] == 'B') cntB++;
        }
        if(cntA != a + c + d && cntB != b + c + d){
            cout << "NO" << endl;
            continue;
        }
        s.push_back(s[n - 1]);
        vector<int> A , B , C;
        int cnt = 0 , tot = 0;
        for(int i = 0 ; i <= n ; i++){
            if(i > 0 && s[i] == s[i - 1]){
                if(cnt % 2 == 1){
                    B.push_back(cnt);
                    tot += cnt / 2;
                }
                else if(s[i] == 'A'){
                    A.push_back(cnt);
                    tot += cnt / 2 - 1;
                }
                else{
                    C.push_back(cnt);
                    tot += cnt / 2;
                }
                cnt = 0;
            }
            cnt++;
        }
        sort(all(A));
        sort(all(C) , greater<int>());
        for(int i : A){
            int mn = min(d , i / 2);
            d -= mn;
            tot -= min(mn , i / 2 - 1);
        }
        for(int i : B){
            int mn = min(d , i / 2);
            d -= mn;
            tot -= mn;
        }
        for(int i : C){
            int mn = min(d , i / 2 - 1);
            if(mn == 0) continue;
            d -= mn;
            tot -= mn + 1;
        }
        if(tot < c || d != 0){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
    }

    return 0;
}
/*

*/