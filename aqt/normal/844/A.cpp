#include <bits/stdc++.h>

using namespace std;

string s;
vector<char> v;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    int K;
    cin >> K;
    if(s.size() < K){
        cout << "impossible" << endl;
        return 0;
    }
    for(int i = 0; i<s.size(); i++){
        v.push_back(s[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    cout << max(0, (int) (K-v.size())) << endl;
}