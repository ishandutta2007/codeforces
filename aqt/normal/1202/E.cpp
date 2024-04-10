#include <bits/stdc++.h>

using namespace std;

string s;
int L, N, B = 450;
int lps[200005];
vector<string> v;
int trie[200005][30], idx = 0;
int ed[200005];
long long cnt[200005][2];
string arr[200005];

void solve(int x){
    for(int i = 1; i<=N; i++){
        string t = arr[i];
        if(t.size() >= B){
            v.push_back(t);
        }
        else{
            int crnt = 0;
            for(char c : t){
                if(!trie[crnt][c-'a']){
                    trie[crnt][c-'a'] = ++idx;
                }
                crnt = trie[crnt][c-'a'];
            }
            ed[crnt]++;
        }
    }
    for(auto t : v){
        for(int i = 0, j = 1; j<t.size(); ){
            if(t[i] == t[j]){
                lps[j++] = ++i;
            }
            else if(i){
                i = lps[i-1];
            }
            else{
                j++;
            }
        }
        for(int i = 0, j = 0; i<L; ){
            if(s[i] == t[j]){
                i++, j++;
                if(j == t.size()){
                    cnt[i-1][x]++;
                }
            }
            else if(j){
                j = lps[j-1];
            }
            else{
                i++;
            }
        }
    }
    for(int i = 0; i<L; i++){
        int crnt = 0;
        for(int j= i; j<L; j++){
            if(trie[crnt][s[j]-'a']){
                crnt = trie[crnt][s[j]-'a'];
            }
            else{
                break;
            }
            cnt[j][x] += ed[crnt];
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> s >> N;
    L = s.size();
    for(int i =1 ; i<=N; i++){
        cin >> arr[i];
    }
    solve(0);
    reverse(s.begin(), s.end());
    for(int i=1; i<=N; i++){
        reverse(arr[i].begin(), arr[i].end());
    }
    v.clear();
    for(int i = 0; i<=idx; i++){
        ed[i] = 0;
        for(int j= 0;j <26; j++){
            trie[i][j] = 0;
        }
    }
    idx = 0;
    solve(1);
    long long ans = 0;
    for(int i = 0; i<L-1; i++){
        //cout << i << " " << L-i-2 << " " << cnt[i][1] << " " << cnt[L-i-1][0] << endl;
        ans += cnt[i][1]*cnt[L-i-2][0];
    }
    cout << ans << endl;
}