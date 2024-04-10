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

int main() {
    bool gotit=0;
    int ans=0;
    unordered_set<char> sett;
    for(int i='a';i<='z';i++) sett.insert(i);
    int n;
    char c;
    string s;
    cin>>n;
    for(int i=0;i<n-1;++i) {
        cin>>c>>s;
        if(gotit && c!='.') ans++;
        else {
            if(c=='?' || c=='.') {
                for(char c:s) sett.erase(c);
            } else {
                vi v(26,1);
                for(char c:s) v[c-'a']=0;
                for(int j=0;j<26;j++) if(v[j]) sett.erase(j+'a');
            }
            if(sett.size()==1) gotit=1;
        }
    }
    cin>>c>>s;
    cout<<ans<<endl;
}