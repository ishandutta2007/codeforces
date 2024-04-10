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
vector<vector<int> > comps;
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
            comps.push_back(comp);
		}
}
 
int main(int argc, char *argv[])
{
    /*
    cin>>n>>m;
    bool**tab=new bool*[n];
    
    for(int i=0;i<n;i++)
    {
            int k;
            cin>>k;
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
    cout<<comps.size()-1<<endl;
    */
    int n;
    cin>>n;
    int*a=new int[2*n];
    
    for(int i=0;i<n;i++)
    {
    cin>>a[i];
    a[i+n]=a[i];
    }
    
    int s,t;
    cin>>s>>t;
    
    if(s==t)
    cout<<0<<endl;
    else
    {
        if(s>t)
        swap(s,t);
        int min=2000000000;
        int cur=0;
        for(int i=s-1;i<t-1;i++)
        cur+=a[i];
        min=cur;
        cur=0;
        for(int i=s+n-2;i>=t-1;i--)
        cur+=a[i];
        if(cur<min)
        min=cur;
        cout<<min<<endl;
        
    }
    
    return EXIT_SUCCESS;
}