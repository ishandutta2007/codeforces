#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;

struct ratio
{
    int a, b;
    
    bool operator<(const ratio& r) const
    {
        return a * (ll)r.b < r.a * (ll)b;
    }
};

const int maxN = 100500;
bool ours[maxN];
vector<int> edgesTo[maxN];

int ourNeighbours[maxN];

ratio getRatio(int i)
{
    ratio r;
    r.a = ourNeighbours[i];
    r.b = edgesTo[i].size();
    return r;
}

int main()
{
    int nVertices, nEdges, nNotOurs;
    scanf("%d %d %d", &nVertices, &nEdges, &nNotOurs);
    
    for (int i = 0; i < nVertices; i++)
        ours[i] = true;
    
    for (int i = 0; i < nNotOurs; i++)
    {
        int v;
        scanf("%d", &v);
        v--;
        
        ours[v] = false;
    }
    
    for (int i = 0; i < nEdges; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        
        edgesTo[u].push_back(v);
        edgesTo[v].push_back(u);
    }
    
    set<pair<ratio, int>> ratios;
    
    for (int i = 0; i < nVertices; i++)
        if (ours[i])
        {
            ratio r;
            r.a = 0;
            r.b = edgesTo[i].size();
            for (int u: edgesTo[i])
                if (ours[u])
                    ourNeighbours[i]++;
                
            ratios.insert(make_pair(getRatio(i), i));
        }
        
    ratio bestRatio = (*ratios.begin()).first;
    int bestRemoves = 0;
    vector<int> removes;
    
    //printf("first ratio %d %d\n", bestRatio.a, bestRatio.b);
    while (!ratios.empty())
    {
        pair<ratio, int> minPair = *ratios.begin();
        ours[minPair.second] = false;
        ratios.erase(minPair);
        
        //printf("removed %d\n", minPair.second + 1);
        
        removes.push_back(minPair.second);
        
        if (ratios.empty()) break;
        
        for (int x: edgesTo[minPair.second])
        {
            if (!ours[x]) continue;
            
            ratios.erase(make_pair(getRatio(x), x));
            ourNeighbours[x]--;
            ratios.insert(make_pair(getRatio(x), x));
        }
        
        ratio minRatio = (*ratios.begin()).first;
        //printf("new ratio %d %d\n", minRatio.a, minRatio.b);
        if (bestRatio < minRatio)
        {
            //printf("new best ratio\n");
            bestRatio = minRatio;
            bestRemoves = removes.size();
        }
    }
    
    for (int i = 0; i < (int)removes.size(); i++)
        ours[removes[i]] = true;
    
    for (int i = 0; i < bestRemoves; i++)
        ours[removes[i]] = false;
    
    int answerSize = 0;
    for (int i = 0; i < nVertices; i++)
        if (ours[i])
            answerSize++;
        
    printf("%d\n", answerSize);
    for (int i = 0; i < nVertices; i++)
        if (ours[i])
            printf("%d ", i + 1);
    printf("\n");
    
    return 0;
}