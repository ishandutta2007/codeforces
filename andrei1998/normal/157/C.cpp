#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

char s1[6005];
#define s1 (s1+2000)

char s2[4005];

int main()
{
    int n,m;

    cin.get(s1+1,4005);
    cin.get();
    cin.get(s2+1,4005);

    n=strlen(s1+1);
    m=strlen(s2+1);

    int ans=6005;
    int curent;
    for(int i=-2000;i<=n;i++){
        curent=0;
        for(int j=1;j<=m;j++)
            curent+=(s1[i+j-1]!=s2[j]);

        ans=min(ans,curent);
    }

    cout<<ans<<'\n';
    return 0;
}