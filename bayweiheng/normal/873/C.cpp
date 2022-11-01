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
    int n,m,k;
    cin>>n>>m>>k;
    vvi v(m,vi(n,0));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            scanf("%d",&v[j][i]);
        }
    }
    int maxscore=0;
    int totones=0;
    for(int i=0;i<m;i++) {
        int cursum=0;
        int maxsum;
        int maxones=0;
        int numones=0;
        for(int j=0;j<k;j++) {
            if (v[i][j]) cursum++;
        }
        maxsum=cursum;
        for(int j=0;j<n-k;j++) {
            if (v[i][j]) numones++;
            cursum+=v[i][j+k];
            cursum-=v[i][j];
            if (cursum>maxsum) {
                maxones=numones;
                maxsum=cursum;
            }
        }
        totones+=maxones;
        maxscore+=maxsum;
    }
    printf("%d %d\n",maxscore,totones);
}