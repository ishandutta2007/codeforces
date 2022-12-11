#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <set>
using namespace std;

set<pair<int, int>> bombes;
int puis[100 * 1000];
int nbD[100 * 1000];

int main()
{
	int nbBombes;
	cin >> nbBombes;
	
	for(int iBombe = 0;iBombe < nbBombes;iBombe++)
	{
		int pos;
		cin >> pos >> puis[iBombe];
		bombes.insert(make_pair(-pos, iBombe));
	}
	
	int mel = 0;
	for(auto it = bombes.rbegin();it != bombes.rend();it++)
	{
		auto suiv = bombes.upper_bound(make_pair(it->first+ puis[it->second], 10*1000*1000));
		if(suiv == bombes.end())
			nbD[it->second] = 1;
		else
			nbD[it->second] = 1 + nbD[suiv->second];
		mel = max(mel, nbD[it->second]);
	}
	cout << nbBombes - mel << endl;
	return 0;
}