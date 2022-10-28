#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }

const int N=1e5+5;

int32_t main()
{
    IOS;
    vector<int> v(3);
    for(int i=0;i<3;i++)
    {
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    int a1=-1, b1=-1, a2=-1, b2=-1, check1=1, check2=1;
    int lcm=(v[1]*v[2])/gcd(v[1], v[2]);
    for(int i=0;i<=1e7;i++)
    {
        if(i%v[0]==0)
            continue;
        if(a1==-1)
        {
            a1=i%v[1];
        }
        else if((i-a1)%v[1]!=0)
        {
            if(b1==-1)
                b1=i%v[2];
            else
            {
                if(i%v[2]!=b1)
                {
                    check1=0;
                }
            }
        }
        if(b2==-1)
        {
            b2=i%v[2];
        }
        else if((i-b2)%v[2]!=0)
        {
            if(a2==-1)
                a2=i%v[1];
            else
            {
                if(i%v[1]!=a2)
                {
                    check2=0;
                }
            }
        }
    }
    if(check1||check2)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
    return 0;
}