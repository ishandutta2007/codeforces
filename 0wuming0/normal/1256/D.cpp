#include"bits/stdc++.h"
using namespace std;
#define ll long long
char s[1000007];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        scanf("%s",s);
        ll l=-1,r=-1;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
                l=i;
                while(s[i]=='1')i++;i--;
                r=i;
                goto ou;
            }
            if(i==n-1)
            {
                printf("%s\n",s);
                goto ne;
            }
        }
        ou:;
        while(1)
        {
            if(r==n-1)
            {
                printf("%s\n",s);
                goto ne;
            }
            if(k<r-l+1)
            {
                while(k--)
                {
                    swap(s[r],s[r+1]);
                    r--;
                }
                printf("%s\n",s);
                goto ne;
            }
            k-=r-l+1;
            swap(s[r+1],s[l]);
            l++;
            r++;
            while(s[r]=='1')r++;r--;
        }
        ne:;
    }
    return 0;
}