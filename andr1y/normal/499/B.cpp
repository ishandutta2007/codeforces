#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define ull unsigned ll
#define pll pair<ll, ll>
#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define endl '\n'
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#define M 1000000007
#define N 200000
#define INF 101111111111111
using namespace std;
map<string, string> dict;
string _min(string s1, string s2){
    if(s1.length() <= s2.length()) return s1;
    else return s2;
}
main(){
    FAST;
    ll n, m;
    cin >> n >> m;
    for(ll i = 0;i<m;i++){
        string s1, s2;
        cin >> s1 >> s2;
        dict[s1] = s2;
    }
    for(ll i  =0;i<n;i++){
        string s;
        cin >> s;
        cout << _min(s, dict[s]) << " ";
    }
}