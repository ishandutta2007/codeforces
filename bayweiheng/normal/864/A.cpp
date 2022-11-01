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
    int n,cur;
    cin>>n;
    unordered_map<int,int> m;
    for(int i=0;i<n;i++) {
        cin>>cur;
        m[cur]++;
    }
    bool ok=true;
    int arr[2];
    int idx=0;
    for(auto p:m) {
        if (p.second!=n/2) {
            ok=0;
            break;
        } else {
            arr[idx]=p.first;
            idx++;
        }
    }
    if (ok) {
        cout<<"YES"<<endl;
        printf("%d %d\n",arr[0],arr[1]);
    } else {
        cout<<"NO"<<endl;
    }
}