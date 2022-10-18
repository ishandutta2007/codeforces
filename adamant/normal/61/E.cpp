#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MPOW=21;
const int N=1<<MPOW-1;
const int N2=N<<1;
struct sg_tree
{
    int arr[N2];

    sg_tree(){fill(arr,arr+N2,0);}

    void add(int x,int num)
    {
        x+=N;
        arr[x]=(arr[x]+num);
        while(x>>=1)arr[x]=(arr[x<<1]+arr[(x<<1)+1]);
    }

    int get_sum(int c,int cl,int cr,int l,int r)
    {
        if(l==cl && r==cr)
            return arr[c];
        if(l>r)
            return 0;
        int cm=cl+cr>>1;
        return (get_sum(c<<1,cl,cm,l,min(cm,r))+get_sum((c<<1)+1,cm+1,cr,max(l,cm+1),r));
    }

    int get_sum(int r)
    {
        return get_sum(1,0,N-1,r,N-1);
    }
} SG;

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k=3;
    cin>>n;

    vector<int> in(n);

    for(int i=0;i<n;i++)
        cin>>in[i];

    vector<int> inv(n);
    fill(begin(inv),end(inv),1);

    map<int,int> nw;
    vector<int> T(in);
    sort(T.begin(),T.end());
    T.resize(unique(T.begin(),T.end())-T.begin());
    for(int i=0;i<n;i++) nw[T[i]]=i;
    for(int i=0;i<n;i++) in[i]=nw[in[i]];

    for(int i=1;i<k;i++)
    {
        SG=sg_tree();
        for(int j=0;j<n;j++)
        {
            int cur=SG.get_sum(in[j]);
            SG.add(in[j],inv[j]);
            inv[j]=cur;
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)
        ans=(ans+inv[i]);
    cout<<ans<<endl;


}