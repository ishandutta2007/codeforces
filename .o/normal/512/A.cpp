#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <numeric>
#include <deque>
#include <utility>
#include <bitset>
#include <limits.h>
#include <iostream>

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;

char name[105][105];
int n;
bool G[30][30];
int deg[30];

queue<int> que;
bool visited[30];

string ans;
int outdeg[30];

int main() {

    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%s", name[i]+1);
        int j;
        for(j = 0; name[i][++j]; ) {
            if(!name[i-1][j]) break;
            if(name[i][j] != name[i-1][j]) {
                G[name[i-1][j] - 'a'][name[i][j] - 'a'] = true;
                break;
            }
        }
        if(!name[i][j]) {
            if(name[i-1][j]) {
                return 0 & puts("Impossible");
            }
        }
    }
    
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < 26; j++) {
            if(G[j][i]) ++deg[i];
            if(G[i][j]) ++outdeg[i];
        }
        if(deg[i] == 0) que.push(i);
    }
    
    while(!que.empty()) {
        int u = que.front(); que.pop();
        //putchar((char)u + 'a');
        ans.push_back((char)u + 'a');

        for(int j = 0; j < 26; j++) if(G[u][j]) {
            --deg[j];
            if(deg[j] == 0) que.push(j);
        }
    }

    if(ans.length() != 26) puts("Impossible");
    else puts(ans.c_str());
    return 0;
}