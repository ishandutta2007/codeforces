#include <bits/stdc++.h>
using namespace std;

int n,a[100];
int main(){
    int lo=0,up=1e9;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",a+i),lo=max(lo,a[i]);

    lo--;
    while(up-lo>1){
        int md=(lo+up)>>1;
        long long hs=0,os=0;
        for(int i=0;i<n;i++) hs+=a[i],os+=md-a[i];
        if(hs<os) up=md;
        else lo=md;
    }
    printf("%d\n",up);

    return 0;
}