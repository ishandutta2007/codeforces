#include <iostream>

using namespace std;

int main()
{
    int n,m,k;
    cin >> n >> m >> k;
    int p[n],s[n],c[k];
    for(int i=0;i<n;i++) cin >> p[i];
    for(int i=0;i<n;i++) cin >> s[i];
    for(int i=0;i<k;i++) cin >> c[i];
    int best[m+1];
    for(int i=0;i<=m;i++) best[i]=0;
    for(int i=0;i<n;i++) best[s[i]]=max(best[s[i]],p[i]);
    int res=0;
    for(int i=0;i<k;i++) if(best[s[c[i]-1]]!=p[c[i]-1]) res++;
    cout << res << endl;
    return 0;
}