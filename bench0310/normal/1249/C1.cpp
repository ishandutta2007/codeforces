#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q;
    scanf("%d",&q);
    while(q--)
    {
        long long n;
        scanf("%I64d",&n);
        vector<int> v;
        while(n)
        {
            v.push_back(n%3);
            n/=3;
        }
        v.push_back(0);
        int id=-1;
        for(int i=0;i<(int)v.size();i++)
        {
            if(v[i]==2) id=i;
        }
        if(id!=-1)
        {
            for(int i=id+1;i<(int)v.size();i++)
            {
                if(v[i]==0)
                {
                    v[i]=1;
                    for(int j=i-1;j>=0;j--) v[j]=0;
                    break;
                }
            }
        }
        if(v.back()==0) v.pop_back();
        reverse(v.begin(),v.end());
        long long m=0;
        for(int b:v) m=(3*m+b);
        printf("%I64d\n",m);
    }
    return 0;
}