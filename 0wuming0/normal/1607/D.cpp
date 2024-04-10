#include"bits/stdc++.h"
using namespace std;
#define ll long long
int a[200005];
char s[200005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%d",a+i);
        scanf("%s",s);
        multiset<int>s1,s2;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='B')s1.insert(a[i]);
            else s2.insert(a[i]);
        }
        int now=1;
        while(s1.size())
        {
            if(*s1.begin()<now)
            {
                cout<<"no"<<endl;
                goto ne;
            }
            s1.erase(s1.begin());
            now++;
        }
        while(s2.size())
        {
            if(*s2.begin()>now)
            {
                cout<<"no"<<endl;
                goto ne;
            }
            s2.erase(s2.begin());
            now++;
        }
        cout<<"yes"<<endl;
        ne:;
    }
    return 0;
}