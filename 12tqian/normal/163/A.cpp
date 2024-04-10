#include <bits/stdc++.h>
using namespace std;
const long MOD = 1000000007;
const int MAX = 5005;
static int dp[MAX][MAX];
int change(char a){
    return ((int) a) - 'a';
}

int main(){
    string s1, t1;
    cin >> s1 >> t1;
    vector<int> s;
    vector<int> t;
    for(int i = 0; i<s1.length(); i++){
        s.emplace_back(change(s1.at(i)));
    }
    for(int i = 0; i<t1.length(); i++){
        int ch = change(t1.at(i));
        t.emplace_back(ch);
    }
    for(int i = 0; i<s.size(); i++){
        if(s[i] == t[t.size() - 1]){
            dp[i][t.size() - 1] = 1;
        }
    }

    for(int i = s.size()-1; i>=0; i--){
        for(int j = t.size()-1; j>= 0; j--){
            dp[i][j] = dp[i][j+1]%MOD;
            if(s[i] == t[j]){
                dp[i][j] += ((dp[i+1][j+1] + 1)%MOD);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i<s.size(); i++){
        ans += (dp[i][0]%MOD);
        ans = ans%MOD;
    }
    cout<< ans%MOD;
    return 0;
}