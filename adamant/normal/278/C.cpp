#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include <numeric>
 
using namespace std;
 
#define ll long long

const ll MAXN=10000;
int n,m;
vector<int> g[MAXN];
bool used[MAXN];
vector<int> comp;
 ll found=0;
void dfs (int v) {
	used[v] = true;
	comp.push_back (v);
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (! used[to])
			dfs (to);
	}
}
 
void find_comps() {
	for (int i=0; i<n; ++i)
		used[i] = false;
	for (int i=0; i<n; ++i)
		if (! used[i]) {
			comp.clear();
			dfs (i);
			found++;
		}
}
 
int main(int argc, char *argv[])
{
    cin>>n>>m;
    bool**tab=new bool*[n];
    bool ok=true;
    for(int i=0;i<n;i++)
    {
            int k;
            cin>>k;
            if(k)
            ok=false;
            tab[i]=new bool[m];
            
            for(int j=0;j<m;j++)
            tab[i][j]=0;
            int t;
            for(int j=0;j<k;j++)
            {
            cin>>t;
            tab[i][t-1]=true;
            }
    }
    
    for(int i=0;i<n-1;i++)
    for(int j=i+1;j<n;j++)
    for(int k=0;k<m;k++)
    if(tab[i][k] && tab[j][k])
    {
                 g[i].push_back(j);
                 g[j].push_back(i);
                 break;
    }
    find_comps();
    if(ok)
    cout<<n<<endl;
    else
    cout<<found-1<<endl;
    
    return EXIT_SUCCESS;
}