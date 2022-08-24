#include <bits/stdc++.h>

using namespace std;

int main() {
    string s = "abcdefghijklmnopqrstuvwxyz";
    int n;
    cin >> n;
    string a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int counter = 0;
    int mmax = 0;
    for(int i = 0; i < s.length(); i++){
        for(int j = 0; j < s.length(); j++){
            counter = 0;
            for(int t = 0; t < n; t++){
                string r = a[t];
                bool b = true;
                for(int k = 0; k < a[t].length(); k++){
                    if(r[k] != s[i] && r[k] != s[j]){
                        b = false;
                        break;
                    }
                }
                if(b){
                    counter += r.length();
                }
            }
            mmax = max(counter, mmax);
        }
    }
    cout << mmax;
}