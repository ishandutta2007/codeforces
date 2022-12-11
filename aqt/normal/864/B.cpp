#include <bits/stdc++.h>

using namespace std;

string s;
int N;

int main(){
    cin >> N >> s;
    int ans = 0;
    for(int i = 1; i<=N; i++){
        set<char> r;
        for(int j = i; j<=N; j++){
            if(s[j-1] >= 'A' && s[j-1] <= 'Z'){
                break;
            }
            r.insert(s[j-1]);
        }
        ans = max(ans, (int) r.size());
    }
    cout << ans << endl;
}