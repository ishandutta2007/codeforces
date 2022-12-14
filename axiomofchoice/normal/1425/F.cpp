#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],n;

int Q(int L,int R) {
    printf("? %d %d\n",L,R);
    fflush(stdout);
    int ans;
    scanf("%d",&ans);
    return ans;
}


int main() {
    cin>>n;
    int a23=Q(2,3);
    int a13=Q(1,3);
    a[1]=a13-a23;
    int a12=Q(1,2);
    a[2]=a12-a[1];
    a[3]=a23-a[2];
    for(int i=4;i<=n;i++) {
        int x=Q(i-1,i);
        a[i]=x-a[i-1];
    }
    printf("!");
    for(int i=1;i<=n;i++) printf(" %d",a[i]);
    fflush(stdout);
}