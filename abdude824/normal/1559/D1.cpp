// C++ implementation of disjoint set
#include <bits/stdc++.h>
using namespace std;
class DisjSet {
    int *rank, *parent, n;

public:
    DisjSet(int n)
    {
        rank = new int[n];
        parent = new int[n];
        this->n = n;
        makeSet();
    }

    void makeSet()
    {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        // Finds the representative of the set
        // that x is an element of
        if (parent[x] != x) {

            // if x is not the parent of itself
            // Then x is not the representative of
            // his set,
            parent[x] = find(parent[x]);

            // so we recursively call Find on its parent
            // and move i's node directly under the
            // representative of this set
        }

        return parent[x];
    }

    // Do union of two sets represented
    // by x and y.
    void Union(int x, int y)
    {
        // Find current sets of x and y
        int xset = find(x);
        int yset = find(y);

        // If they are already in same set
        if (xset == yset)
            return;

        // Put smaller ranked item under
        // bigger ranked item if ranks are
        // different
        if (rank[xset] < rank[yset]) {
            parent[xset] = yset;
        }
        else if (rank[xset] > rank[yset]) {
            parent[yset] = xset;
        }

        // If ranks are same, then increment
        // rank.
        else {
            parent[yset] = xset;
            rank[xset] = rank[xset] + 1;
        }
    }
};

int main()
{
    int n;cin>>n;
    DisjSet obj(n);
    DisjSet obj2(n);
    int m1,m2;
    cin>>m1>>m2;
    for(int i=0;i<m1;i++)
    {
        int x,y;cin>>x>>y;
        obj.Union(x-1, y-1);
    }
    for(int i=0;i<m2;i++)
    {
        int x,y;cin>>x>>y;
        obj2.Union(x-1, y-1);
    }
    vector<pair<int,int>> a;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(obj.find(j)!=obj.find(i)&&obj2.find(j)!=obj2.find(i))
            {
                obj.Union(i,j);
                obj2.Union(i,j);
                a.push_back({i,j});
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    for(int i=0;i<a.size();i++)
        cout<<a[i].first+1<<" "<<a[i].second+1<<"\n";
    return 0;
}