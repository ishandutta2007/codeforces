
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
    int n,cur;
    vi edges;
    cin>>n;
    for(int i=0;i<n-1;i++) {
        cin>>cur;
        edges.push_back(cur-1);
    }
    vi colors;
    for(int i=0;i<n;i++) {
        cin>>cur;
        colors.push_back(cur);
    }
    int ans=1;
    for(int i=0;i<n-1;i++) {
        if(colors[i+1]!=colors[edges[i]]) ans++;
    }
    cout<<ans<<endl;
}