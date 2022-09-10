#include <bits/stdc++.h>

using namespace std;

vector <int> res;

int main() {
    int n, w=0;
    scanf("%d", &n);
    for(int i=1;i<=n;++i){
        bool k=true;
        for(int j=1;j<=n;++j){
            int a;
            scanf("%d", &a);
            if(a==1||a==3)
                k=false;
        }
        if(k){
            ++w;
            res.push_back(i);
        }
    }
    printf("%d\n", w);
    for(int i=0;i<w;++i)
        printf("%d ", res[i]);
    return 0;
}