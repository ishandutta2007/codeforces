#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        int tab[26];
        for (int i = 0; i < 26; ++i) {
            tab[i]=0;
        }
        for (int i = 0; i < s.size(); ++i) {
            ++tab[s[i]-'a'];
        }
        bool t = true;
        for (int i = 0; i< 26; ++i) {
            if (tab[i]>1) t=false;
        }
        if (t==false) {
            cout << "No\n";
        } else {
            int sum = 0;
            for (int i = 0; i < 26; ++i) {
                sum+=tab[i];
                if (sum>0 && tab[i]==0 && sum < s.size()) { cout << "No\n"; t=false; break;}
            }
            if (t==true)
            cout << "Yes\n";
        }
    }
}