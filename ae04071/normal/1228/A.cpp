#include <bits/stdc++.h>
using namespace std;

bool diff(int val) {
    int cnt[10]={0,};
    while(val) {
        if(cnt[val%10]++) return false;
        val/=10;
    }
    return true;
}
int main() {
    int l,r;
    scanf("%d%d",&l,&r);
    for(int i=l;i<=r;i++)if(diff(i)) {
        printf("%d\n",i);
        return 0;
    }
    puts("-1");
    return 0;
}