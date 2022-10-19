#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N=100005;

int n;
char a[N],b[N];

int t[2][2];
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("forest.in","r",stdin);
    //freopen("forest.out","w",stdout);
    cin>>n;
    cin>>a;
    cin>>b;
    long long ans=0;
    for(int i=0;i<n;++i)
    {
        int x=a[i]-'0';
        int y=b[i]-'0';
        for(int j=0;j<2;++j)
        {
            for(int k=0;k<2;++k)
            {
                if(!((j|k)==(x|k) && (x|y)==(j|y)))
                    ans+=t[j][k];
            }
        }
        t[x][y]++;
    }
    cout<<ans<<endl;
    return 0;
}