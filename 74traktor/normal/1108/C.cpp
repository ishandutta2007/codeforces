#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector < char > go = {'R', 'G', 'B'};
    pair < int, string > ans = {(int)1e9, ""};
    for (int i = 0; i < 3; ++i){
        for (int j = 0; j < 3; ++j){
            for (int z = 0; z < 3; ++z){
                if (i != j && i != z && j != z){
                    int kol = 0;
                    string s2 = "";
                    for (int pos = 0; pos < n; ++pos){
                        if (pos % 3 == 0){
                            if (s[pos] != go[i]) kol++;
                            s2 += go[i];
                        }
                        else if (pos % 3 == 1){
                            if (s[pos] != go[j]) kol++;
                            s2 += go[j];
                        }
                        else{
                            if (s[pos] != go[z]) kol++;
                            s2 += go[z];
                        }
                    }
                    pair < int, string > W = {kol, s2};
                    ans = min(ans, W);
                }
            }
        }
    }
    cout << ans.first << endl;
    cout << ans.second << endl;
    return 0;
}