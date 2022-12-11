#include <bits/stdc++.h>

using namespace std;

mt19937 g1(chrono::steady_clock::now().time_since_epoch().count());
string s, t;
int N;
const long long MOD = 1e9+7;
long long hsh[2][100005];
long long pows[2][100005];
long long sd[2] = {31, 131};
int fre[100005];
pair<long long, long long> h[100005];
vector<int> pos[100005];
vector<int> lst[100005];
int ans[100005];
int sz[100005];
set<int> st;
map<int, int> qu;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    uniform_int_distribution<int> distribution(MOD/2, MOD-2);
    sd[0] = distribution(g1);
    sd[1] = distribution(g1);
    pows[0][0] = pows[1][0] = 1;
    for(int i = 1; i<=s.size(); i++){
        pows[0][i] = pows[0][i-1] * sd[0];
        pows[1][i] = pows[1][i-1] * sd[1];
        pows[0][i] %= MOD, pows[1][i] %= MOD;
        hsh[0][i] = (hsh[0][i-1]*sd[0] + s[i-1]-'a'+1)%MOD;
        hsh[1][i] = (hsh[1][i-1]*sd[1] + s[i-1]-'a'+1)%MOD;
    }
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> fre[i] >> t;
        sz[i] = t.size();
        pos[sz[i]].push_back(i);
        st.insert(sz[i]);
        for(char c : t){
            h[i].first = (h[i].first*sd[0] + c-'a'+1)%MOD;
            h[i].second = (h[i].second*sd[1] + c-'a'+1)%MOD;
        }

        //qu[h[i].first*h[i].second] = i;
    }
    for(int l : st){
        for(int n : pos[l]){
            qu.insert({(h[n].first*h[n].second), n});
        }
        for(int i = l; i<=s.size(); i++){
            long long h1 = (hsh[0][i] - hsh[0][i-l]*pows[0][l]%MOD + MOD)%MOD;
            long long h2 = (hsh[1][i] - hsh[1][i-l]*pows[1][l]%MOD + MOD)%MOD;
            if(qu.count((h1*h2))){
                lst[qu[(h1*h2)]].push_back(i);
            }
        }
        for(int n : pos[l]){
            ans[n] = INT_MAX;
            for(int k = fre[n]-1; k<lst[n].size(); k++){
                ans[n] = min(ans[n], lst[n][k]-lst[n][k-fre[n]+1]);
            }
            ans[n] = (ans[n] == INT_MAX ? -1 : ans[n] + sz[n]);
        }
        qu.clear();
    }
    for(int i = 1; i<=N; i++){
        cout << ans[i] << "\n";
    }
}