#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <ctgmath>
#include <functional>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define x first
#define y second

//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
char x[3][111];

int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%s%s%s",x[0],x[1],x[2]);
        int l=strlen(x[0]);
        int flag = 1;
        for(int j=0;j<l;j++){
            if(x[1][j]==x[2][j]||x[2][j]==x[0][j]) continue;
            else flag = 0;
        }
        puts(flag?"YES":"NO");
    }
}