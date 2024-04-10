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
    string s;
    int n;
    cin>>n;
    cin>>s;
    if (s[0]=='S'&&s[s.size()-1]=='F') cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}