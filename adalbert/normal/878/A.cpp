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
typedef long double ld;
const int arr=2e5;

int get(int u, int i)
{
    return((u&(1<<i))!=0);
}

int type[30];

signed main()
{
    int n;
    cin>>n;
    int now=0;
    for (int i=1;i<=n;i++)
    {
        char ch;
        int a;
        cin>>ch>>a;

        if (ch=='|')
        {
            for (int i=0;i<=9;i++)
                if (get(a,i))
                type[i]=2;
        } else
        if (ch=='&')
        {
            for (int i=0;i<=9;i++)
            {
                if (!get(a,i))
                    type[i]=3;
            }

        } else
        {
            for (int i=0;i<=9;i++)
                if (get(a,i))
                {
                    if (type[i]==0)
                        type[i]=1; else
                    if (type[i]==1)
                        type[i]=0; else
                    if (type[i]==2)
                        type[i]=3; else
                        type[i]=2;
                }
        }
    }

    int c1=0,c2=(1<<10)-1,c3=0;

    for (int i=0;i<=9;i++)
    {
        if (type[i]==1)
        c3+=(1<<i); else
        if (type[i]==2)
        c1+=(1<<i); else
        if (type[i]==3)
        c2-=(1<<i);
    }


    cout<<3<<'\n';
    cout<<"| "<<c1<<'\n';
    cout<<"& "<<c2<<'\n';
    cout<<"^ "<<c3<<'\n';
}
/*
!!! https://pastebin.com/jHpxMZq3
https://ideone.com/LNWtNX
*/