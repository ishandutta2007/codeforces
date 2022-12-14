#include <bits/stdc++.h>

using namespace std;

map <char, long long> mp;
bool mark[50];

int main(){
    long long n, door;
    cin >> n >> door;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
        mp[s[i]] ++;
    long long guard = 0;
    for (int i = 0; i < n; i++){
        if (!mark[s[i] - '0']){
            mark[s[i] - '0'] = true;
            guard ++;
            if (guard > door)
                return cout << "YES" << endl, 0;
        }
        mp[s[i]] --;
        if (mp[s[i]] == 0)
            guard --;
    }
    cout << "NO" << endl;
}