#include <iostream>

#define int long long int
using namespace std;

int v[500005];
int n;

int s_part[500005];
int s_part2[500005];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin>>n;

    int s=0;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        s+=v[i];
    }

    for(int i=1;i<=n;i++)
        s_part[i]=s_part[i-1]+v[i];

    for(int i=n;i>=1;i--)
        s_part2[i]=s_part2[i+1]+v[i];

    if(s%3!=0){
        cout<<"0\n";
        return 0;
    }
    s/=3;

    int smen=0;
    int ans=0;

    for(int i=1;i<=n;i++){
        if(i-2>=1 && s_part[i-2]==s)
            smen++;

        if(s_part2[i]==s)
            ans+=smen;
    }

    cout<<ans<<'\n';
    return 0;
}