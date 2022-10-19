#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N=200005;

int main()
{
    //freopen("input.txt","r",stdin);
    int n;
    cin>>n;
    for(int a=n;a>=1;--a)
    {
        for(int b=n-a;b>=1;--b)
        {
            int c=n-a-b;
            if(a%3!=0 && b%3!=0 && c%3!=0)
            {
                cout<<a<<' '<<b<<' '<<c<<endl;
                return 0;
            }
        }
    }
    return 0;
}