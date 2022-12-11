#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

#define err(...) fprintf(stderr, __VA_ARGS__)

typedef pair<int,int> pi;
typedef long long int64;
typedef vector<int> vi;

#define fore(i,n) for(int i = 0; i < (n); i++)
#define tr(i,c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define x first
#define y second
#define mp make_pair
#define pb push_back

char s[124567];

int main()
{
	int n,m,a,k;
	map<string,int> skill;
	scanf("%d%d 0.%d", &n, &m, &k);
	fore(i,n)
	{
		scanf("%s%d", s, &a);
		int ns = k*a/100;
		if(ns < 100) continue;
		skill[s] = ns;
	}
	fore(i,m)
	{
		scanf("%s", s);
		if(skill.find(s) == skill.end()) skill[s] = 0;
	}
	printf("%d\n", skill.size());
	tr(i,skill) printf("%s %d\n", i->x.c_str(), i->y);
}