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
    int n,m;
    cin>>n>>m;
    int ai,bi;
    int pos=0;
    bool flag=0;
    while(n--) {
        cin>>ai>>bi;
        if(ai<=pos) pos=max(pos,bi);
        if(pos==m) flag=1;
    }
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}