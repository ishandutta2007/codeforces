#include <bits/stdc++.h>
using namespace std;

const int MOD=998244353;

string s;
int n;

int main(){
    cin >> n;
    cin >> s;
    int cnt1=1, cnt2=1;
    for (int i=1; i<s.size(); i++){
        if (s[i]==s[i-1]) cnt1++;
        else break;
    }
    for (int i=s.size()-2; i>=0; i--){
        if (s[i]==s[i+1]) cnt2++;
        else break;
    }
    if (s[0]==s[s.size()-1]){
        cout << 1LL*(cnt1+1)*(cnt2+1)%MOD << endl;
    } else {
        cout << cnt1+cnt2+1 << endl;
    }
    return 0;
}