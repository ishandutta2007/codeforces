#include <iostream>
#include <string>

using namespace std;

int main() {
    int q, sl, tl;
    bool failed;
    string s,t;
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> q;
    for(int i = 0; i < q; i ++) {
        failed = false;
        cin >> s >> t;
        sl = s.length();
        tl = t.length();
        if(s[0] != t[0]) {
            cout << "-1" << endl;
            continue;
        }
        int j = 1;
        for(; j % sl != 0 || j % tl != 0; j ++) {
            if(s[j%sl] != t[j%tl]) {
                cout << "-1" << endl;
                failed = true;
                break;
            }
        }
        if(failed) {continue;}

        for(; j > 0; j -= sl) {
            cout << s;
        }
        cout << endl;
    }
    return 0;
}