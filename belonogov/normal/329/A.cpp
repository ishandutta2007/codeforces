#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <cmath>

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

const int maxn = 200;
const int inf = 1e9;

char a[maxn][maxn];
vector < pair < int, int > > ans;

int main(){
   // freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    int n;
    bool flag;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%s", a[i]);


    for(int t = 0; t < 2; t++){
        ans.clear();
        bool fail = 0;
        for(int i = 0; i < n; i++){
            flag = 1;
            for(int j = 0; j < n && flag; j++)
                if (a[i][j] == '.'){
                    ans.pb(mp(i, j));
                    flag = 0;
                }
            if (flag)
                fail = 1;
        }
        if (!fail){
            for(int i = 0; i < n; i++)
                if (t == 0)
                    printf("%d %d\n", ans[i].fr + 1, ans[i].sc + 1);
                else
                    printf("%d %d\n", ans[i].sc + 1, ans[i].fr + 1);
            return 0;
        }
        for(int i = 0; i < n; i++)
            for(int j = i; j < n; j++)
                swap(a[i][j], a[j][i]);
    }
    printf("-1\n");
    return 0;
}