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

bool is_upp(char c) {
    return c<=90 && c>=65;
}

int main() {
    int n;
    string s;
    cin>>n;
    cin>>s;
    unordered_set<char> ss;
    int ans=0;
    for(int i=0;i<n;i++) {
        char c=s[i];
        if (is_upp(c)) {
            int a=ss.size();
            ans=max(ans,a);
            ss.clear();
        } else ss.insert(c);
    }
    ans=max(ans,(int) ss.size());
    cout<<ans<<endl;
}