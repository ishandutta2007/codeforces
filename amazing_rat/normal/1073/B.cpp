#include<bits/stdc++.h>
using namespace std;
const int maxn=200000+100;
 int a[maxn],b[maxn],c[maxn];
int main()
{
    int n,x;
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++){
            scanf("%d",&x);
            a[x]=i;///xi
        }
        for(int i=1;i<=n;i++){
            scanf("%d",&x);
            b[i]=x;
        }
        int last=0;
        for(int i=1;i<=n;i++){
            c[i]=max(0,a[b[i]]-last);
            last=max(last,a[b[i]]);
        }
        for(int i=1;i<=n;i++){
            cout<<c[i]<<" ";
        }
        cout<<endl;
    }
}