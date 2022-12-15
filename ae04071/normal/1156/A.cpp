#include <bits/stdc++.h>
using namespace std;

int n,arr[100];
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",arr+i);

    int ans=0;
    for(int i=1;i<n;i++) {
        if(arr[i-1]==1) {
            if(arr[i]==2) ans+=3;
            else ans+=4;
        } else if(arr[i-1]==2) {
            if(arr[i]==1) ans+=3;
            else {
                puts("Infinite");
                return 0;
            }
        } else {
            if(arr[i]==1) ans+=4;
            else {
                puts("Infinite");
                return 0;
            }
        }
   }
    for(int i=2;i<n;i++) {
        if(arr[i]==2&&arr[i-1]==1&&arr[i-2]==3) {
            ans--;
        }
    }
    puts("Finite");
    printf("%d\n",ans);

    return 0;
}