#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> cnt(n + 1);
        for(int i = 0; i < n; i++) cnt.at(0) = 0;
        for(int i = 0; i < n; i++){
            cin >> a.at(i);
            cnt.at(a.at(i))++;
        }
        int min_ = n + 1;
        int pos = -1;
        for(int i = 0; i < n; i++){
            if(cnt.at(a.at(i)) >= 2) continue;
            else if(a.at(i) < min_){
                min_ = a.at(i);
                pos = i + 1;
            }
        }
        cout << pos << endl;
    }
    return 0;
}