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

const ll MAX = 200;
const ll MAXN = 1e4;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int q , n , cntR , cntB , F[MAX] , mark[MAX];
string s;

int getF(int x){
    if(x < MAX){
        return F[x];
    }
    return F[x - ((x - MAX) / 34 + 1) * 34];
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    for(int i = 4 ; i < MAX ; i++){
        memset(mark , 0 , sizeof(mark));
        for(int j = 2 ; j + 1 < i ; j++){
            mark[F[j] ^ (F[i - j])] = 1;
        }
        for(int j = 0 ; j < MAX ; j++){
            if(!mark[j]){
                F[i] = j;
                break;
            }
        }
    }

    cin >> q;
    while(q--){
        cin >> n >> s;
        cntR = cntB = 0;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == 'R') cntR++;
            if(s[i] == 'B') cntB++;
        }
        if(cntR > cntB){
            cout << "Alice" << endl;
            continue;
        }
        if(cntB > cntR){
            cout << "Bob" << endl;
            continue;
        }
        int ans = 0 , cnt = 0;
        for(int i = 1 ; i <= n ; i++){
            if(i == n || s[i] == s[i - 1]){
                ans ^= getF(cnt + 3);
                cnt = 0;
                continue;
            }
            cnt++;
        }
        cout << (ans == 0 ? "Bob" : "Alice") << endl;
    }

    return 0;
}
/*

*/