#include <bits/stdc++.h>

#define st first
#define nd second

using namespace std;

int t[100007];

int main() {
    int n, w=0;
    scanf("%d", &n);
    for(int i=1;i<=n;++i)
        scanf("%d", &t[i]);
    sort(t+1,t+n+1);
    int pref=0;
    for(int i=1;i<=n;++i)
        if(pref<=t[i]){
            ++w;
            pref+=t[i];
        }
    printf("%d\n", w);
    return 0;
}