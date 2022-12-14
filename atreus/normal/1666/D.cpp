# include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 77;
int tst , n;
string s , t;
bool f[100];
void test() {
    memset(f , 0 , sizeof f);
    cin >> s >> t;
    int szs = s.size();
    int szt = t.size();
    int curt = szt - 1;
    for(int i = szs - 1;i >= 0;-- i) {
        if(curt < 0) break ;
        f[i] = (s[i] == t[curt]);
        if(s[i] != t[curt]) continue ;
        for(int j = i + 1;j < szs;++ j)
            if(s[j] == t[curt] && ! f[j]) {
                cout << "NO\n";
                return ;
            }
        curt --;
    }

    if(curt < 0) cout << "YES\n";
    else cout << "NO\n";
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> tst;
    while(tst --)
        test();
    return 0;
}