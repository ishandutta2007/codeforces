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

void INC(string &a)
{
     if(a[a.size()-1]<'z')
     a[a.size()-1]++;
     else
     {
         a[a.size()-1]='a';
         int col=1;
         for(int i=a.size()-2;i>=0;i--)
         if(a[i]<'z')
         {
         a[i]++;
         col=0;
         break;
         }
         else
         {
         a[i]='a';
         }
         if(col)
         {
         string t(a.size()+1,'a');
         a=t;
         }
     }
}
 vector<int> z_function (string s) {
	int n = (int) s.length();
	vector<int> z (n);
	for (int i=1, l=0, r=0; i<n; ++i) {
		if (i <= r)
			z[i] = min (r-i+1, z[i-l]);
		while (i+z[i] < n && s[z[i]] == s[i+z[i]])
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
	}
	return z;
}
bool find(string a, string b)
{
     string c=a+'#'+b;
     vector<int> d=z_function(c);
     for(int i=a.size()+1;i<c.size();i++)
     if(d[i]==a.size())
     return 1;
     return 0;
     
}
 
int main(int argc, char *argv[])
{
    int n;
    cin>>n;
    string*a=new string[n];
    
    for(int i=0;i<n;i++)
    cin>>a[i];
string cur = "a";

while (true) {
bool f = 0;
for (int i = 0; i < n; i++)
if (find(cur, a[i])) f = 1;
if (!f) return cout << cur, 0;
INC(cur);
}
    
    return EXIT_SUCCESS;
}