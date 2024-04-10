#include <bits/stdc++.h>

using namespace std;

int K, Q;
string s;
string t;
int cnt[26][200005];
int pre[26][200005];
set<int> st;

int main(){
    cin >> K >> t >> Q;
    for(int i =1; i<=K; i++){
        s += t;
    }
    int lvl = 0;
    for(; (1<<(lvl+1))<=s.size(); lvl++);
    for(char c = 'a'; c<='z'; c++){
        for(int i = 1; i<=s.size(); i++){
            if(s[i-1] == c){
                for(int j = i; j<=s.size(); j+=j&-j){
                    cnt[c-'a'][j]++;
                }
            }
        }
    }
    while(Q--){
        int k;
        char c;
        cin >> k >> c;
        int idx = 0, sum = 0;
        for(int j = lvl; j>=0; j--){
            if(idx + (1<<j) <= s.size() && sum + cnt[c-'a'][idx+(1<<j)] < k){
                sum += cnt[c-'a'][idx+(1<<j)];
                idx += (1<<j);
            }
        }
        assert(!st.count(idx));
        st.insert(idx);
        s[idx] = '0';
        for(int i = idx+1; i<=s.size(); i+=i&-i){
            cnt[c-'a'][i]--;
        }
    }
    for(int i = 0; i<s.size(); i++){
        if(s[i] != '0'){
            cout << s[i];
        }
    }
}