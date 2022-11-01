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


int main() {
    string s;
    cin>>s;
    int n=s.size();
    vi left(n,0);
    vi right(n,0);
    int lcount=0;
    int rcount=0;
    for(int i=0;i<n;i++) {
        if(s[i]=='Q') lcount++;
        else if(s[i]=='A') left[i]=lcount;
    }
    for(int i=n-1;i>=0;i--) {
        if(s[i]=='Q') rcount++;
        else if(s[i]=='A') right[i]=rcount;
    }
    int ans=0;
    for(int i=0;i<n;i++) {
        ans+=left[i]*right[i];
    }
    cout<<ans<<endl;
}