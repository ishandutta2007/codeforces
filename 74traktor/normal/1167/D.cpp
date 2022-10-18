#include <bits/stdc++.h>

using namespace std;

int open[2];

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector < int > st;
    for (auto c : s){
        if (c == '('){
            if (open[0] <= open[1]){
                cout << 0;
                open[0]++;
            }
            else{
                cout << 1;
                open[1]++;
            }
        }
        else{
            if (open[0] >= open[1]){
                cout << 0;
                open[0]--;
            }
            else{
                cout << 1;
                open[1]--;
            }
        }
    }
    return 0;
}