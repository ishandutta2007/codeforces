#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    char s[n+1];
    scanf("%s",s);
    vector<int> a(n);
    for(int i=0;i<n;i++) a[i]=(s[i]-'0');
    vector<int> b(n);
    for(int i=0;i<k;i++) for(int j=i;j<n;j+=k) b[j]=a[i];
    if(a>b)
    {
        for(int i=k-1;i>=0;i--)
        {
            if(a[i]==9) continue;
            for(int j=i;j<n;j+=k) b[j]=a[i]+1;
            for(int o=i+1;o<k;o++) for(int j=o;j<n;j+=k) b[j]=0;
            break;
        }
    }
    printf("%d\n",n);
    for(int i=0;i<n;i++) printf("%d",b[i]);
    printf("\n");
    return 0;
}