#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef long long ll;
typedef vector<ll> vll;

vs v;

bool checkFull(int i) {
    int bigr=i/3;
    int bigc=i%3;
    int str=bigr*4;
    int stc=bigc*4;
    for(int i=str;i<str+3;i++) {
        for(int j=stc;j<stc+3;j++) {
            if(v[i][j]=='.') return false;
        }
    }
    return true;
}

bool modify(int i) {
    int bigr=i/3;
    int bigc=i%3;
    int str=bigr*4;
    int stc=bigc*4;
    for(int i=str;i<str+3;i++) {
        for(int j=stc;j<stc+3;j++) {
            if(v[i][j]=='.') v[i][j]='!';
        }
    }
}

int main() {
    string s;
    for(int i=0;i<11;i++) {
        getline(cin,s,'\n');
        v.push_back(s);
    }
    int x,y;
    cin>>x>>y;
    x--;y--;
    int bigr=x%3,bigc=y%3;
    int j=bigr*3+bigc;
    if(checkFull(j)) {
        for(int i=0;i<9;i++) modify(i);
    } else {
        modify(j);
    }
    for(string s:v) {
        cout<<s<<endl;
    }
}