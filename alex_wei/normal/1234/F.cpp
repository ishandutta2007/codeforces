#include<bits/stdc++.h>
using namespace std;
const int N=1048576;
int n,c[N],ans;
string s;
int main()
{
	cin>>s,n=s.size();
    for(int i=1;i<=n;i++)
        s[i-1]-='a';
    for(int i=1;i<=n;i++){
        int a=0;
        for(int j=i;j<=n;j++)
            if(a&(1<<s[j-1]))break;
            else a+=1<<s[j-1],c[a]=j-i+1;
    }
    for(int i=1;i<N;i++){
        if(c[i])continue;
        for(int j=0;j<20;j++)
            if(i&(1<<j))c[i]=max(c[i],c[i^(1<<j)]);
    }
    for(int i=1;i<(1<<20);i++){int P=~i;P&=(1<<20)-1;ans=max(ans,c[i]+c[P]);}
    printf("%d\n",ans);
    return 0;
}