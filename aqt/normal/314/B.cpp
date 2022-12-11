#include <bits/stdc++.h>

using namespace std;

int nxt[105], cnt[105];

int main(){
    int t1, t2;
    string s1, s2;
    cin >> t1 >> t2 >> s1 >> s2;
    for(int i = 0; i<s2.size(); i++){
        int idx = i;
        for(int j = 0; j<s1.size(); j++){
            if(s2[idx] == s1[j]){
                idx++;
                if(idx == s2.size()){
                    cnt[i]++;
                    idx = 0;
                }
            }
        }
        nxt[i] = idx;
    }
    int idx = 0, ans = 0;
    for(int t = 1; t<=t1; t++){
        ans += cnt[idx];
        idx = nxt[idx];
    }
    cout << ans / t2 << endl;
}