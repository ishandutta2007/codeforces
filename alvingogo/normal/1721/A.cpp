#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

int main(){
    AquA;
    int t;
    cin >> t;
    while(t--){
        string a,b;
        cin >> a >> b;
        vector<char> v;
        v.push_back(a[0]);
        v.push_back(a[1]);
        v.push_back(b[0]);
        v.push_back(b[1]);
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        cout << v.size()-1 << "\n";
    }
    return 0;
}