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
    int v1,v2,v3,m;
    cin>>v1>>v2>>v3>>m;
    if(m>2*v3 || v3>2*m || m>=v2) cout<<-1<<endl;
    else {
        int a=min(v3,m);
        cout<<2*v1<<endl<<2*v2<<endl<<2*a<<endl;
    }
}