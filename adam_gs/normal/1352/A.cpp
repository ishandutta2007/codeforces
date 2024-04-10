#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--) {
        int k;
        cin >> k;
        int p=1;
        vector<int>w;
        while(k>0) {
            if(k%10!=0) {
                w.push_back(k%10*p);
            }
            p*=10;
            k/=10;
        }
        cout << w.size() << '\n';
        for(int i = 0; i < w.size(); ++i) {
            cout << w[i] << " ";
        }
        cout << '\n';
    }
}