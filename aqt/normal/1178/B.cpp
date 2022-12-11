#include <bits/stdc++.h>

using namespace std;

string s;
vector<long long> v;

long long f(long long a){
    return a*(a-1)/2;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    s += "o";
    v.push_back(0);
    long long tot = 0;
    for(int i= 1; i<=s.size(); i++){
        if(s[i-1] == 'o'){
            tot += max(0LL, i-2-v.back());
            v.push_back(i);
        }
    }
    long long ans = 0;
    long long pre = 0;
    for(int i = 1; i<(v.size()-1); i++){
        pre += max(0LL, v[i]-v[i-1]-2);
        ans += pre*(tot-pre);
    }
    cout << ans << endl;
}