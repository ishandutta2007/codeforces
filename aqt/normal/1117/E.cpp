#include <bits/stdc++.h>

using namespace std;

string s;
int N;
vector<char> q[3];
string a[3];
map<vector<char>, int> mp;
int idx[100000];
string ans;

int main(){
    cin >> s;
    N = s.size();
    int lst = 1;
    for(int p = 26, c = 0; p<=17576; p*=26, c++){
        for(int i = 0; i<N; i++){
            q[c].push_back((char) ('a' + (i%p/lst)));
        }
        lst = p;
    }
    //cout << q[0].size() << " " << q[1].size() << " " << q[2].size() << endl;
    for(int i = 0; i<N; i++){
        vector<char> v = {q[0][i], q[1][i], q[2][i]};
        mp[v] = i;
    }
    for(int k = 0; k<3; k++){
        cout << "? ";
        for(int i = 0; i<N; i++){
            cout << q[k][i];
        }
        cout << endl;
        cin >> a[k];
    }
    for(int i = 0; i<N; i++){
        vector<char> v = {a[0][i], a[1][i], a[2][i]};
        idx[mp[v]]= i;
    }
    cout << "! " ;
    for(int i = 0; i<N; i++){
        cout << s[idx[i]];
    }
    cout << endl;
}