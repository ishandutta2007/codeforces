#include <bits/stdc++.h>

using namespace std;

int N;
string s;
int BIT[26][100005];

void upd(int t, int n, int v){
    for(int i = n; i<=N; i+=i&-i){
        BIT[t][i]+=v;
    }
}

int query(int t, int n){
    int ret = 0;
    for(int i = n; i>0; i-=i&-i){
        ret += BIT[t][i];
    }
    return ret;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    N = s.size();
    for(int i = 0; i<s.size(); i++){
        upd(s[i]-'a', i+1, 1);
    }
    int Q;
    cin >> Q;
    while(Q--){
        int c;
        cin >> c;
        if(c == 1){
            int p;
            char k;
            cin >> p >> k;
            upd(s[p-1]-'a', p, -1);
            s[p-1] = k;
            upd(s[p-1]-'a', p, 1);
        }
        else{
            int l, r;
            cin >> l >> r;
            int out = 0;
            for(int b = 0; b<26; b++){
                out += (query(b, r)-query(b, l-1) > 0);
            }
            cout << out << "\n";
        }
    }
}