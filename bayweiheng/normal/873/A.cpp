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
    int n,k,x,cur;
    cin>>n>>k>>x;
    stack<int> s;
    for(int i=0;i<n;i++) {
        cin>>cur;
        s.push(cur);
    }
    int ans=0;
    while(!s.empty()){
        cur=s.top();
        s.pop();
        if (x<cur&&k>0) {
            ans+=x;
            k--;
        } else {
            ans+=cur;
        }
    }
    cout<<ans<<endl;
}