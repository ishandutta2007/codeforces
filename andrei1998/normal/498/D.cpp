#include <iostream>
#include <cstring>

#define NMAX 100000
#define mod 60
using namespace std;

struct node {
    int left,right;
    int time[mod]; //Time to traverse

    node (int left=0, int right=0): left(left), right(right) {
        //memset(time,0,sizeof(time));
    }
}arb[4*NMAX+5];

inline void unite (node &a, node b, node &c) {
    //a.left=b.left;
    //a.right=c.right;

    for(int i=0;i<mod;i++)
        a.time[i]=b.time[i]+c.time[(i+b.time[i])%mod];
}

int a[NMAX+5];
void build (int left, int right, int pos) {
    arb[pos].left=left,arb[pos].right=right;

    if(left==right) {
        for(int i=0;i<mod;i++)
            if(i%a[left])
                arb[pos].time[i]=1;
            else
                arb[pos].time[i]=2;
        return;
    }

    int mijl=(left+right)>>1;
    build(left,mijl,pos<<1);
    build(mijl+1,right,(pos<<1)+1);

    unite(arb[pos],arb[pos<<1],arb[(pos<<1)+1]);
}

void update (int up_pos, int val, int pos) {
    if(arb[pos].left==arb[pos].right) {
        for(int i=0;i<mod;i++)
            if(i%val)
                arb[pos].time[i]=1;
            else
                arb[pos].time[i]=2;
        return;
    }

    int mijl=(arb[pos].left+arb[pos].right)>>1;
    if(up_pos<=mijl)
        update(up_pos,val,pos<<1);
    else
        update(up_pos,val,(pos<<1)+1);

    unite(arb[pos],arb[pos<<1],arb[(pos<<1)+1]);
}

int ans;
void query (int x, int y, int pos) {
    if(arb[pos].left==x && arb[pos].right==y) {
        ans+=arb[pos].time[ans%mod];
        return;
    }

    int mijl=(arb[pos].left+arb[pos].right)>>1;
    if(y<=mijl)
        query(x,y,pos<<1);
    else if(x>mijl)
        query(x,y,(pos<<1)+1);
    else {
        query(x,mijl,pos<<1);
        query(mijl+1,y,(pos<<1)+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n=0;
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>a[i];
    build(1,n,1);

    int q=0;
    cin>>q;

    char type;
    int x,y;

    while(q--) {
        cin>>type>>x>>y;

        if(type=='A') {
            y--;

            ans=0;
            query(x,y,1);
            cout<<ans<<'\n';
        }
        else
            update(x,y,1);
    }

    return 0;
}