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
    cin>>n;
    unordered_set<string> ss;
    string s;
    while(n--) {
        cin>>s;
        if (ss.count(s)) cout<<"YES"<<endl;
        else {
            ss.insert(s);
            cout<<"NO"<<endl;
        }
    }

}