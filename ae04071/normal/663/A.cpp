#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr;
    char ch;
    int sg=1,a=0,s=0;
    while(true) {
        scanf(" %c",&ch);
        if(ch=='=') break;
        if(ch=='?') {
            arr.push_back(sg);
            if(sg==1) a++;
            else s++;
        } else if(ch=='+') sg=1;
        else sg=-1;
    }

    int l=0,r=0,n;
    scanf("%d",&n);
    for(auto &v:arr) {
        if(v==1) l++,r+=n;
        else l-=n,r--;
    }
    if(l<=n && n<=r) {
        puts("Possible");

        int rem = n - (a-s),f=0;
        for(auto &v:arr) {
            if(v==1) {
                if(f) printf(" + ");
                if(rem>0) {
                    printf("%d",1+min(n-1,rem));
                    rem-=min(n-1,rem);
                } else printf("1");
            } else {
                if(f) printf(" - ");
                if(rem<0) {
                    printf("%d",1+min(n-1,-rem));
                    rem+=min(n-1,-rem);
                }else printf("1");
            }
            f=1;
        }
        printf(" = %d\n",n);
        
    } else puts("Impossible");
    
    return 0;
}