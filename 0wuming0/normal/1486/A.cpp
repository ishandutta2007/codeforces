#include"bits/stdc++.h"
using namespace std;
long long a[105];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        long long sum=0;
        for(int i=1;i<=n;i++)
        {
            int c;
            cin>>c;
            sum+=c;
            if(sum<i*(i-1)/2)
            {
                cout<<"no"<<endl;
                i++;
                for(;i<=n;i++)
                {
                    cin>>c;
                }
                goto ne;
            }
        }
        cout<<"yes"<<endl;
        ne:;
    }
    return 0;
}
/*
1
1
0
*/