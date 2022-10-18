#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int a[n];
    int s = 0;
    vector < int > xot;
    set < int > s1;
    map < int, int > m;
    for (int i = 0; i < n; ++i){
        cin >> a[i];
        s += a[i];
        if (s1.find(a[i]) == s1.end()){
            s1.insert(a[i]);
            m[a[i]] = 1;
        }
        else{
            m[a[i]] += 1;
        }
    }
    //cout << s << endl;
    for (int i = 0; i < n; ++i){
        if (m[a[i]] == 1)
            s1.erase(a[i]);
        int imax = (*s1.rbegin()), tec = s - a[i];
        if (tec - imax == imax)
            xot.push_back(i + 1);
        s1.insert(a[i]);
    }
    cout << xot.size() << endl;
    for (auto k : xot)
        cout << k << " ";
    return 0;
}