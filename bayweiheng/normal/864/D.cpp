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
    scanf("%d",&n);
    vi v;
    vi dup(n+1,0);
    for(int i=0;i<n;i++) {
        scanf("%d",&cur);
        v.push_back(cur);
        dup[cur]++;
    }
    vi sorted;
    for(int i=1;i<=n;i++) {
        if (dup[i]==0) sorted.push_back(i);
    }
    printf("%d\n",sorted.size());
    int idx=0;
    for(int i=0;i<n;i++) {
        int cur=v[i];
        int left=dup[cur];
        if (left==-1) { //must change
            v[i]=sorted[idx];
            idx++;
        } else if (left>1) { //can change
            if (sorted[idx]<v[i]) { //good to change
                v[i]=sorted[idx];
                idx++;
                dup[cur]--;
            } else { // don't change, but everything else has to
                dup[cur]=-1;
            }
        }
    }
    printf("%d",v[0]);
    for(int i=1;i<n;i++) printf(" %d",v[i]);
}