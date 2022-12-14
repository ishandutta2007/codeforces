#include <bits/stdc++.h>

using namespace std;

vector <int> v;

int main() {
	ios_base::sync_with_stdio(false);
    long long n, ans = 1, k = 0;
    string s;
    cin >> n;
    getline(cin, s);
    getline(cin, s);
    int inx = 0;
    for (int i = 0; i < s.size(); i++){
        k ++;
        if (s[i] == '!' || s[i] == '.' || s[i] == '?'){
            v.push_back(k);
            k = 0;
            i ++;
        }
    }
    k = 0;
    for (int i = 0; i < v.size(); i++){
        k += v[i];
        if (v[i] > n){
            cout << "Impossible" << endl;
            return 0;
        }
        if (k > n){
            ans ++;
            k = v[i];
        }
        k ++;
    }
    cout << ans << endl;
}