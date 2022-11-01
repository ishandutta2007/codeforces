#include <bits/stdc++.h>

using namespace std;

vector<bool> is;
int n;
int now=0, ans=0;

int main() {
    //freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    is.assign(n,false);
    for(int i=0; i<2*n; i++){
        int t;
        scanf("%d", &t);
        --t;
        if(is[t]) {
            is[t]=false;
            now--;
        } else {
            is[t]=true;
            now++;
        }
        ans=max(ans,now);
    }
    printf("%d", ans);
}