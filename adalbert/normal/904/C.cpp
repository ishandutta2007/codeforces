#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define m_p make_pair
#define get leirogoerg
#define files(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
#define left dogjreg
#define right dgfdogjreg
typedef long long ll;
typedef double ld;
const int arr=2e5+1000;

bool can[500];

signed main()
{
    int cnt='z'-'a'+1;
    int n;
    cin>>n;
    int res=0;
    while (n--)
    {
        string st;
        cin>>st;
        if (st==".")
        {
            cin>>st;
            for (auto i:st)
            {
                if (!can[i])
                    cnt--;
                can[i]=1;
            }
        } else
        if (st=="!")
        {
            if (cnt==1)
                res++;
            cin>>st;
            for (int c='a';c<='z';c++)
            {
                bool ch=0;
                for (auto i:st)
                    if (i==c)
                    ch=1;
                if (!ch)
                {
                    if (!can[c])
                        cnt--;
                    can[c]=1;
                }
            }

        } else
        {
                if (cnt==1)
                res++;

            cin>>st;
            int i=st[0];
            if (!can[i])
                cnt--;
            can[i]=1;

        }
        //cout<<cnt<<'\n';
    }
    cout<<max(0,res-1);
}