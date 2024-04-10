#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    auto q=[&](int i,int j)->int
    {
        cout << "? " << i << " " << j << endl;
        int o;
        cin >> o;
        if(o==-1) exit(0);
        return o;
    };
    vector<int> z(11,0);
    int c=11;
    mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
    auto rng=[&](int l,int r)->int{return uniform_int_distribution<int>(l,r)(gen);};
    while(c>0)
    {
        int a=rng(1,n);
        int b=rng(1,n);
        if(a==b) b=(1+(a==1));
        int o=q(a,b);
        for(int j=0;j<11;j++) if((o&(1<<j))==0&&z[j]==0) {z[j]=a;c--;}
    }
    int idx=1;
    int mask=(1<<11)-1;
    auto magic=[&](int i)
    {
        int r=0;
        for(int j=0;j<11;j++)
        {
            if((mask&(1<<j))&&i!=z[j])
            {
                int o=q(i,z[j]);
                if(o&(1<<j)) r|=(1<<j);
            }
        }
        idx=i;
        mask=r;
    };
    magic(1);
    for(int i=2;i<=n;i++)
    {
        int o=q(idx,i);
        if((mask|o)==mask) magic(i);
    }
    assert(mask==0);
    vector<int> p(n+1,0);
    for(int i=1;i<=n;i++) if(i!=idx) p[i]=q(idx,i);
    cout << "!";
    for(int i=1;i<=n;i++) cout << " " << p[i];
    cout << endl;
    return 0;
}