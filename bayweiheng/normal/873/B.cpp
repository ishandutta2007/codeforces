#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <list>
#include <cstring>
#include <queue>
#include <bitset>
#include <set>
#include <stack>
#include <complex>
#include <functional>

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
    int n;
    string s;
    cin>>n;
    cin>>s;
    int ans=0;
    unordered_map<int,int> m;
    m[0]=-1;
    int counter=0;
    for(int i=0;i<n;i++) {
        if (s[i]=='0') {
            counter--;
        } else counter++;
        if (m.count(counter)) {
            ans=max(ans,i-m[counter]);
        } else m[counter]=i;
    }
    cout<<ans<<endl;
}