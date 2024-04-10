#include <bits/stdc++.h>
using namespace std;

int n,a[1001],pi[1001];

void getpi(){
    int i=0;
    for(int j=1;j<n;j++){
        while(i && a[i]!=a[j]) i=pi[i-1];
        if(a[i]==a[j]) pi[j]=++i;
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);

    for(int i=n;i;i--)
        a[i]=a[i]-a[i-1];
    for(int i=0;i<n;i++)
        a[i]=a[i+1];

    getpi();

    int lst=n;
    vector<int> ans;
    while(lst){
        ans.push_back(n-pi[lst-1]);
        lst=pi[lst-1];
    }
    printf("%d\n",ans.size());
    for(auto &v:ans)
        printf("%d ",v);

    return 0;
}