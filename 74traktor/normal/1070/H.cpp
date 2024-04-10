#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();
    int n;
    cin >> n;
    set < string > s;
    map < string, int > m;
    map < string, string > m1;
    for (int i = 0; i < n; ++i){
        string st;
        cin >> st;
        set <string> se;
        for (int dl = 1; dl <= (int) st.size(); dl++){
            for (int j = 0; j <= (int) st.size() - dl; ++j){
                string s1 = "";
                for (int q = j; q < j + dl; ++q){
                    s1 += st[q];
                }
                if (s.find(s1) == s.end()){
                    m[s1] = 1;
                    m1[s1] = st;
                    s.insert(s1);
                    se.insert(s1);
                }
                else{
                    if (se.find(s1) == se.end()){
                        se.insert(s1);
                        m[s1] += 1;
                    }
                }
            }
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i){
        string st;
        cin >> st;
        if (s.find(st) == s.end()){
            cout<< 0 << " " << '-' << endl;
        }
        else{
            cout << m[st] << " " << m1[st] << endl;
        }
    }
    return 0;
}