#include"bits/stdc++.h"
using namespace std;
int now[100005];
int save[100005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)now[i]=0;
        for(int i=1;i<=n;i++)if(now[i]==0)
        {
            cout<<"? "<<i<<endl;
            int cnt=0;
            cin>>save[cnt++];
            while(1)
            {
                cout<<"? "<<i<<endl;
                cin>>save[cnt++];
                if(save[cnt-1]==save[0])break;
            }
            for(int i=1;i<cnt;i++)
            {
                now[save[i-1]]=save[i];
            }
        }
        cout<<"!";
        for(int i=1;i<=n;i++)cout<<" "<<now[i];
        cout<<endl;
    }
    return 0;
}