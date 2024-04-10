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

const ll MAXN = 1e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , dv[MAXN] , mark[MAXN];
vector<int> vec[MAXN] , rem;
vector<pii> ans;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    for(int i = 2 ; i < MAXN ; i++){
        if(dv[i])   continue;
        for(int j = i ; j < MAXN ; j += i){
            if(dv[j] == 0)  dv[j] = i;
        }
    }
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        if(i == 1 || (dv[i] == i && i * 2 > n)){
            mark[i] = 1;
            continue;
        }
        vec[dv[i]].push_back(i);
    }
    for(int i = n ; i > 2 ; i--){
        while(SZ(vec[i]) >= 2){
            int x = vec[i].back(); vec[i].pop_back();
            int y = vec[i].back(); vec[i].pop_back();
            mark[x] = mark[y] = 1;
            ans.push_back({x , y});
        }
        if(SZ(vec[i])){
            int x = vec[i].back();
            mark[x] = mark[x * 2] = 1;
            ans.push_back({x , 2 * x});
        }
    }
    for(int i = 1 ; i <= n ; i++){
        if(mark[i] == 0){
            rem.push_back(i);
        }
    }
    while(SZ(rem) >= 2){
        int x = rem.back(); rem.pop_back();
        int y = rem.back(); rem.pop_back();
        mark[x] = mark[y] = 1;
        ans.push_back({x , y});
    }
    cout << SZ(ans) << endl;
    for(pii i : ans){
        cout << i.X << sep << i.Y << endl;
    }

    return 0;
}
/*

*/