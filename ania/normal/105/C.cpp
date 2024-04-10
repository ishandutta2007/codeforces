#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
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

char buff1[1111], buff2[1111], buff3[1111];

struct resident
{
	string name, home;
	int value, type;
	void read()
	{
		scanf("%s%s%d%s", buff1, buff2, &value, buff3);
		name = buff1;
		home = buff3;
		if(buff2[0] == 'g') type = 0;
		else if(buff2[0] == 's') type = 1;
		else type = 2;
	}
	bool operator< (resident x) const
	{
		if(value != x.value) return value > x.value;
		return name < x.name;
	}
};

struct item
{
	string name;
	int value, size,type;
	void read()
	{
		int atk,def,res;
		scanf("%s%s%d%d%d%d",buff1,buff2,&atk,&def,&res,&size);
		name = buff1;
		if(buff2[0] == 'w')
		{
			type = 0;
			value = atk;
		}
		else if(buff2[0] == 'a')
		{
			type = 1;
			value = def;
		}
		else
		{
			type = 2;
			value = res;
		}
	}
	int get(vector<resident> r)
	{
		int w = min(size, int(r.size()));
		int q = value;
		fore(i,w) q += r[i].value;
		return q;
	}
};

vector<item> items[3];
vector<resident> residents[3];
int best[3], who[3], fst[3];

int main()
{
	fore(i,3) best[i] = -1;
	int n,k,sum=0;
	scanf("%d", &n);
	fore(i,n)
	{
		item temp;
		temp.read();
		items[temp.type].pb(temp);
		sum += temp.size;
	}
	scanf("%d", &k);
	fore(i,k)
	{
		resident temp;
		temp.read();
		residents[temp.type].pb(temp);
	}
	if(sum == k)
	{
		map<string, int> val[3];
		map<string, vector<string> > rr;
		fore(i,3) fore(j,residents[i].size())
		{
			val[residents[i][j].type][residents[i][j].home] += residents[i][j].value;
			rr[residents[i][j].home].pb(residents[i][j].name);
		}
		fore(i,3) fore(j,items[i].size()) if(items[i][j].value + val[items[i][j].type][items[i][j].name] > best[i])
		{
			best[i] = val[items[i][j].type][items[i][j].name] + items[i][j].value;
			who[i] = j;
		}
		fore(i,3)
		{
			string nn = items[i][who[i]].name;
			int cur = items[i][who[i]].type;
			printf("%s %d", nn.c_str(), rr[nn].size());
			tr(j,rr[nn]) printf(" %s", j->c_str());
			printf("\n");
		}
		return 0;
	}
	fore(i,3) sort(residents[i].begin(), residents[i].end());
	fore(i,3) fore(j,items[i].size())
	{
		int value = items[i][j].get(residents[i]);
		if(value > best[i])
		{
			best[i] = value;
			who[i] = j;
		}
	}
	fore(i,3) fst[i] = items[i][who[i]].size;
	fore(i,3)
	{
		vector<string> rr;
		int cur = who[i];
		if(items[i][cur].size <= residents[i].size())
		{
			printf("%s %d", items[i][cur].name.c_str(), items[i][cur].size);
			fore(j,items[i][cur].size) printf(" %s", residents[i][j].name.c_str());
			printf("\n");
			continue;
		}
		fore(j,residents[i].size()) rr.pb(residents[i][j].name);
		int left = items[i][cur].size - residents[i].size();
		fore(q,3) if(fst[q] < residents[q].size())
		{
			while(fst[q] < residents[q].size() && left > 0)
			{
				rr.pb(residents[q][fst[q]].name);
				fst[q]++;
				left--;
			}
		}
		printf("%s %d", items[i][cur].name.c_str(), rr.size());
		tr(j,rr) printf(" %s", j->c_str());
		printf("\n");
	}
}