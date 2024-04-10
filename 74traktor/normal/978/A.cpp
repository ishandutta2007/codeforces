#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector < int > out;
    set < int > use;
    int a[n];
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = n - 1; i >= 0; --i){
        int x = a[i];
        if (use.find(x) == use.end())
            out.push_back(x);
        use.insert(x);
    }
    cout << out.size() << endl;
    for (int i = out.size() - 1; i >= 0; --i)
        cout << out[i] << " ";
    return 0;
}