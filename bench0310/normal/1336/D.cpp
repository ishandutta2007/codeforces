#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n+1,-1);
    vector<int> q(n+1,0);
    vector<int> one(n+1,0);
    vector<int> two(n+1,0);
    vector<int> inc(n+1,0);
    int pi,pt;
    cin >> pi >> pt;
    vector<int> h(n*(n+1)/2+1,0);
    for(int i=1;i<=n+1;i++) h[i*(i-1)/2]=i;
    auto add=[&](int x)
    {
        cout << "+ " << x << "\n";
        cout.flush();
        int &i=inc[x];
        int &t=((++q[x])==1?one[x]:two[x]);
        cin >> i >> t;
        i-=pi;
        t-=pt;
        pi+=i;
        pt+=t;
        if(i>0||q[x]==2) a[x]=h[i]-(q[x]-1);
    };
    add(1);
    add(2);
    add(3);
    add(1);
    if(a[2]!=-1) a[3]=one[1]/a[2];
    else if(a[3]!=-1) a[2]=one[1]/a[3];
    else
    {
        int s=two[1]-one[1]-1;
        if(s==0) a[2]=a[3]=0;
        else if(s==2) a[2]=a[3]=1;
        else if(one[2]==0)
        {
            a[3]=0;
            a[2]=1;
        }
        else
        {
            a[3]=1;
            a[2]=0;
        }
    }
    for(int i=4;i<=n-1;i++)
    {
        add(i);
        if(one[i-1]-(a[i-3]+1)*(a[i-2]+1)==0) a[i]=0;
        else a[i]=h[inc[i]];
    }
    a[n]=(one[n-1]-(a[n-3]+1)*(a[n-2]+1))/(a[n-2]+1);
    cout << "! ";
    for(int i=1;i<=n;i++) cout << a[i] << " \n"[i==n];
    cout.flush();
    return 0;
}