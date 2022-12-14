#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define gibon cin.tie(0); ios::sync_with_stdio(false);

int main()
{
    gibon
    int T;
    cin >> T;
    while(T--)
    {
        int N, S, K;
        cin >> N >> S >> K;
        int chk[1010]={};
        for(int i=0;i<K;i++)
        {
            int tmp;
            cin >> tmp;
            int a=((tmp-S)>0 ? tmp-S : S-tmp);
            if(a<=1000)
                chk[a]++;
        }
        if(chk[0]==0)
        {
            cout << 0 << '\n';
            continue;
        }
        int grd=min(S-1, N-S);
        bool jogun=false;
        for(int i=1;i<=grd;i++)
        {
            if(chk[i]<2)
            {
                cout << i << '\n';
                jogun=true;
                break;
            }
        }
        if(jogun)   continue;
        int i=grd+1;
        while(chk[i]==1)    i++;
        cout << i << '\n';
    }

}