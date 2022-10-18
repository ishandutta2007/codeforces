#include <bits/stdc++.h>

using namespace std;

#define int long long

int mod;

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    mod = 1;
    for (int i = 1; i <= 32; ++i) mod *= 2;
    mod -= 1;
    int n, x = 0, tec = 1, y;
    cin >> n;
    vector < int > st;
    vector < int > d;
    bool f = false;
    for (int i = 1; i <= n; ++i){
        string s;
        cin >> s;
        if (s == "end"){
            if (d.back() == 0){
                tec /= st.back();
            }
            st.pop_back();
            d.pop_back();
        }
        else if (s == "for"){
            cin >> y;
            if (tec > mod){
                d.push_back(1);
            }
            else{
                tec *= y;
                d.push_back(0);
            }
            st.push_back(y);
        }
        else {
            if (tec > mod){
                cout << "OVERFLOW!!!" << '\n';
                return 0;
            }
            x += tec;
            if (x > mod){
                cout << "OVERFLOW!!!" << '\n';
                return 0;
            }
        }
    }
    cout << x << '\n';
    return 0;
}