#include <iostream>
using namespace std;

int main()
{
	int nbVertices;
	cin >> nbVertices;
	
	long long maxX = -1000, maxY = -1000, minX = 1000, minY = 1000;
	long long x, y;
	for(int iVertice = 0;iVertice < nbVertices;iVertice++)
	{
		cin >> x >> y;
		maxX = max(x, maxX);
		maxY = max(y, maxY);
		minX = min(x, minX);
		minY = min(y, minY);
	}
	
	if(nbVertices == 1)
		cout << -1 << endl;
	else if(nbVertices == 2 && (maxX == minX || maxY == minY))
		cout << -1 << endl;
	else
		cout << (maxX - minX) * (maxY - minY) << endl;
	return 0;
}