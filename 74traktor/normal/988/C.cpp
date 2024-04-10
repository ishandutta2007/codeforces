#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    pair < pair < int, int >, pair < int, int > > out;
    bool f = false;
    map < int, pair < int, int > > m;
    for (int i = 0; i < n; ++i){
        int n1;
        cin >> n1;
        vector < int > a;
        int suma = 0;
        for (int j = 0; j < n1; ++j){
            int x;
            cin >> x;
            a.push_back(x);
            suma += x;
        }
        set < int > prom;
        for (int j = 0; j < n1; ++j){
            int suma_tec = suma - a[j];
            if (prom.find(suma_tec) == prom.end() && m.find(suma_tec) != m.end()){
                //cout << suma_tec << endl;
                out = {m[suma_tec], {i, j}};
                f = true;
            }
            m[suma_tec] = {i, j};
            prom.insert(suma_tec);
        }
    }
    if (!f){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
        cout << out.first.first + 1 << " " << out.first.second + 1<< endl;
        cout << out.second.first + 1<< " " << out.second.second + 1<< endl;
    }
    return 0;
}