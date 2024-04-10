#include<algorithm>
#include<cmath>
#include<cstdio>
#include<vector>
#include<map>
#include<string>
#include<iostream>
using namespace std;

#define fore(i,n) for(int i = 0; i < (n); i++)
#define fort(i,n) for(typeof((n).begin()) i = (n).begin(); i != (n).end(); i++)

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;

#define err(...) fprintf(stderr, __VA_ARGS__);

int n,m;
int t[111];
char temp[111];
vector<int> all;
map<string,int> M;

int main()
{
	scanf("%d%d",&n,&m);
	fore(i,n) scanf("%d",&t[i]);
	sort(t,t+n);
	fore(i,m)
	{
		scanf("%s",temp);
		M[temp]++;
	}
	for(map<string,int>::iterator i = M.begin(); i != M.end(); i++)  all.push_back(i->second);
	sort(all.begin(), all.end());
	int k = all.size();
	long long smin = 0, smax = 0;
	fore(i,k)
	{
		smin += 1LL * all[i] * t[k-1-i];
		smax += 1LL * all[i] * t[n-k+i];
	}
	cout << smin << " " << smax << "\n";
}