#include <bits/stdc++.h>
using namespace std;

int n,a[200001],b[400001],pi[200001];

void getpi(int *arr) {
    int i=0;
    for(int j=1;j<n;j++) {
        while(i!=0 && arr[i]!=arr[j]) i=pi[i-1];
        if(arr[i]==arr[j]) pi[j]=++i;
    }
}
bool kmp(int *a,int *b,int n,int m) {
    int i=0;
    for(int j=0;j<m;j++) {
        while(i!=0 && a[i]!=b[j]) i=pi[i-1];
        if(a[i]==b[j]) {
            ++i;
            if(i==n) return true;
        }
    }
    return false;
}
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",a+i);
    for(int i=0;i<n;i++) scanf("%d",b+i);
    
    for(int i=0;i<n;i++) if(!a[i]) {
        for(int j=i+1;j<n;j++) a[j-1]=a[j];
        break;
    }
    for(int i=0;i<n;i++) if(!b[i]) {
        for(int j=i+1;j<n;j++) b[j-1]=b[j];
        break;
    }
    n--;
    for(int i=0;i<n;i++) b[i+n]=b[i];
    
    getpi(a);
    if(kmp(a,b,n,n+n)) puts("YES");
    else puts("NO");

    return 0;
}