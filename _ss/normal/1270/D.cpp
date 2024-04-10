#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll N=1e5+10,mod=1e9+7,inf=1e18;

int main()
{
    int n,k;
    cin>>n>>k;
    if (k==1)
    {
        cout<<"! 1\n";
        cout.flush();
        return 0;
    }
    cout<<"? ";
    for (int i=1;i<=k;i++) cout<<i<<" ";
    cout<<"\n";
    cout.flush();
    int t,vt;
    cin>>vt>>t;
    int d=1,flag=0;
    while (d==vt) d++;
    vector<int> vi1,vi2;
    vi1.pb(vt);
    for (int i=k+1;i<=n;i++)
    {
        cout<<"? ";
        for (int j=1;j<=k;j++)
            if (j!=d) cout<<j<<" ";
        cout<<i<<"\n";
        cout.flush();
        int t2,vt2;
        cin>>vt2>>t2;
        if (t2==t) vi1.pb(i);
        else
        {
            if (t2>t) flag=1;
            else flag=-1;
            vi2.pb(i);
        }
    }
    vector<int> vi3,vi4;
    if (flag==0)
    {
        for (int i=1;i<=k;i++)
            if (i!=d && i!=vt)
            {
                cout<<"? ";
                for (int j=1;j<=k;j++)
                    if (j!=i) cout<<j<<" ";
                cout<<vi1.back()<<"\n";
                cout.flush();
                int t2,vt2;
                cin>>vt2>>t2;
                if (t2==t) vi3.pb(i);
                else
                {
                    if (t2<t) flag=1;
                    else flag=-1;
                    vi4.pb(i);
                }
            }
        if (flag==0)
        {
            cout<<"? ";
            for (int i=1;i<=k+1;i++)
                if (i!=vt) cout<<i<<" ";
            cout<<"\n";
            cout.flush();
            int t2,vt2;
            cin>>vt2>>t2;
            if (t2>t) cout<<"! 1\n";
            else cout<<"! "<<k<<"\n";
            cout.flush();
            return 0;
        }
        if (flag==1) cout<<"! "<<vi3.size()+2<<"\n";
        else cout<<"! "<<vi4.size()+1<<"\n";
        cout.flush();
        return 0;
    }
    for (int i=1;i<=k;i++)
        if (i!=vt && i!=d)
        {
            cout<<"? ";
            for (int j=1;j<=k;j++)
                if (j!=i) cout<<j<<" ";
            cout<<vi2.back()<<"\n";
            cout.flush();
            int t2,vt2;
            cin>>vt2>>t2;
            if (t2!=t) vi3.pb(i);
            else vi4.pb(i);
        }
    if (flag==1) cout<<"! "<<vi3.size()+2<<"\n";
    else cout<<"! "<<vi4.size()+1<<"\n";
    cout.flush();
    return 0;
}