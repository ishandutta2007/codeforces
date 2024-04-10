#include <iostream>
#include <algorithm>
#include <vector>
#include <tr1/unordered_map>
#include <tr1/unordered_set>
#include <map>

#define NMAX 100000
using namespace std;
using namespace tr1;

vector<int> father[NMAX+5];
vector<int> h[NMAX+5];

unordered_map<int,int> harta[NMAX+5];

int find (int cul, int node) {
    if(father[cul][node]!=node)
        father[cul][node]=find(cul,father[cul][node]);
    return father[cul][node];
}

inline void unite (int cul, int node_a, int node_b) {
    node_a=find(cul,node_a);
    node_b=find(cul,node_b);

    if(node_a==node_b)
        return;

    if(h[cul][node_a]<h[cul][node_b])
        father[cul][node_a]=node_b;
    else {
        if(h[cul][node_a]==h[cul][node_b])
            h[cul][node_a]++;
        father[cul][node_b]=node_a;
    }
}

inline bool united (int cul, int node_a, int node_b) {
    node_a=find(cul,node_a);
    node_b=find(cul,node_b);

    return (node_a==node_b);
}

unordered_set<int> graf[NMAX+5];
map<pair<int,int>, int> answers;

int main()
{
    ios_base::sync_with_stdio(false);

    int n=0,m=0;
    cin>>n>>m;

    int a,b,c;
    while(m--) {
        cin>>a>>b>>c;

        if(!harta[c].count(a)) {
            harta[c][a]=harta[c].size()-1;
            father[c].push_back(harta[c].size()-1);
            h[c].push_back(1);
        }

        if(!harta[c].count(b)) {
            harta[c][b]=harta[c].size()-1;
            father[c].push_back(harta[c].size()-1);
            h[c].push_back(1);
        }

        unite(c,harta[c][a],harta[c][b]);

        graf[a].insert(c);
        graf[b].insert(c);
    }

    int q=0;
    cin>>q;

    int ans;
    unordered_set<int>::iterator it;
    while(q--) {
        cin>>a>>b;
        if(a>b)
            swap(a,b);

        if(!answers.count(make_pair(a,b))) {
            ans=0;
            if(graf[a].size()<graf[b].size()) {
                for(it=graf[a].begin();it!=graf[a].end();it++)
                    if(harta[*it].count(b))
                        ans+=united(*it,harta[*it][a],harta[*it][b]);
            }
            else
                for(it=graf[b].begin();it!=graf[b].end();it++)
                    if(harta[*it].count(a))
                       ans+=united(*it,harta[*it][a],harta[*it][b]);
            answers[make_pair(a,b)]=ans;
            cout<<ans<<'\n';
        }
        else
            cout<<answers[make_pair(a,b)]<<'\n';
    }

    return 0;
}