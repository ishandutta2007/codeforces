#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#pragma comment(linker, "/STACK:16777216")
using namespace std;

#define bit(n) (1<<(n))
#define inf 1000000000
#define eps 1e-9
#define PI 3.1415926535897932385
#define pb push_back
#define sz size()
#define mp make_pair
#define cl clear()
#define all(a) a.begin(),a.end()
#define fill(ar,val) memset(ar,val,sizeof ar)
#define MIN(a,b) if(a>(b)) a=(b)
#define MAX(a,b) if(a<(b)) a=(b)
#define sqr(x) ((x)*(x))
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

typedef vector<int> VI;
typedef pair<int,int> PII;
typedef __int64 LL;

map<string,int> score;
map<string,int>::iterator it;
set<string> win;

string s[1111];
int sc[1111];

int main()
{
	//freopen("in.txt","r",stdin);
	int n,i;
	while(cin >> n)
	{
		score.cl;
		for(i=0;i<n;i++)
		{
			cin >> s[i] >> sc[i];
			score[s[i]]+=sc[i];
		}
		int maxsc=0;
		for(it=score.begin();it!=score.end();++it)
			MAX(maxsc,it->second);
		win.cl;
		for(it=score.begin();it!=score.end();++it)
			if(maxsc==it->second) win.insert(it->first);
		score.cl;
		for(i=0;i<n;i++)
		{
			score[s[i]]+=sc[i];
			if(score[s[i]]>=maxsc && win.find(s[i])!=win.end()) break;
		}
		cout << s[i] << endl;
	}
	return 0;
}