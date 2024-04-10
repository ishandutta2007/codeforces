#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
struct elem {
    int lin,col;

    elem (int lin=0, int col=0): lin(lin), col(col) {}
}v[5005];

bool operator< (const elem &a, const elem &b) {
    if(a.lin==b.lin)
        return a.col<b.col;
    return a.lin<b.lin;
}

bool operator== (const elem &a, const elem &b) {
    return (a.lin==b.lin && a.col==b.col);
}

int dist (int lin, int col) {
    return (lin-1)*m+col;
}

int main()
{
    cin>>n>>m;

    int k=0,t=0;
    cin>>k>>t;

    for(int i=1;i<=k;i++)
        cin>>v[i].lin>>v[i].col;

    sort(v+1,v+k+1);

    int x,y,poz,how_many;
    while(t--) {
        cin>>x>>y;

        if(lower_bound(v+1,v+k+1,elem(x,y))!=v+k+1 && v[lower_bound(v+1,v+k+1,elem(x,y))-v]==elem(x,y)) {
            cout<<"Waste\n";
            continue;
        }

        how_many=dist(x,y);
        poz=lower_bound(v+1,v+k+1,elem(x,y))-v-1;
        how_many-=poz;

        if(how_many%3==1)
            cout<<"Carrots\n";
        else if(how_many%3==2)
            cout<<"Kiwis\n";
        else
            cout<<"Grapes\n";
    }

    return 0;
}